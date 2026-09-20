from __future__ import annotations
from dataclasses import dataclass
from os import PathLike
import re


Symbol = tuple[int, str]


def __main():
    symbols_sb4p = read_ida_symbols("SB4P01.map")
    write_kamek_symbols("SB4P.txt", symbols_sb4p)

    for region in ["SB4E", "SB4J", "SB4W", "SB4K"]:
        conv_info = read_symbol_conversion_info(f'convinfo_SB4P_to_{region}.txt')

        symbols_conv = convert_symbols(symbols_sb4p, conv_info)
        write_kamek_symbols(f'{region}.txt', symbols_conv)


# ======================================================================================================================
# Symbol maps
# ======================================================================================================================

__IDA_SYMBOL_PATTERN = re.compile(r'^\s*[0-9A-Z]{4}:([0-9A-Z]{8})\s+(\S+)')


def read_ida_symbols(file_path: str | PathLike, encoding: str = "utf-8") -> list[Symbol]:
    symbols = []

    with open(file_path, "r", encoding=encoding) as f:
        for line in f:
            match = __IDA_SYMBOL_PATTERN.match(line)

            if not match:
                continue

            address = int(match.group(1), 16)
            name = match.group(2)

            if name.startswith("_sub_"):
                name = name[1:]
            if name.startswith("j_"):
                continue
            if name.startswith("str_"):
                continue

            symbols.append((address, name))

    symbols.sort(key=lambda t: t[0])
    return symbols


def write_kamek_symbols(file_path: str | PathLike, symbols: list[Symbol], encoding: str = "utf-8"):
    with open(file_path, "w", encoding=encoding) as f:
        for address, name in symbols:
            f.write(f'{name}=0x{address:08X}\n')


# ======================================================================================================================
# Symbol conversion
# ======================================================================================================================

def convert_symbols(base_symbols: list[Symbol], conv_info: SymConversionInfo) -> list[Symbol]:
    symbols = []

    curr_offset = 0
    curr_index = 0

    for address, name in base_symbols:
        if address in conv_info.deletions:
            continue

        while curr_index < len(conv_info.offsets):
            offset_rule = conv_info.offsets[curr_index]

            if address < offset_rule.address:
                break

            curr_offset = offset_rule.offset
            curr_index += 1

        address += curr_offset
        symbols.append((address, name))

    for addition in conv_info.additions:
        symbols.append((addition.address, addition.name))

    symbols.sort(key=lambda t: t[0])
    return symbols


# ======================================================================================================================
# Conversion info
# ======================================================================================================================

@dataclass(init=True, kw_only=True, frozen=True)
class SymbolOffset:
    address: int
    offset: int


@dataclass(init=True, kw_only=True, frozen=True)
class SymbolAddition:
    address: int
    name: str


@dataclass(init=True, kw_only=True, frozen=True)
class SymConversionInfo:
    offsets: list[SymbolOffset]
    additions: list[SymbolAddition]
    deletions: set[int]


__OFFSET_PATTERN   = re.compile(r'^offset,(0x[0-9a-fA-F]+),(-?0x[0-9a-fA-F]+)')
__ADDITION_PATTERN = re.compile(r'^add,(0x[0-9a-fA-F]+),(\S+)(?:\s*#.*)?$')
__DELETION_PATTERN = re.compile(r'^delete,(0x[0-9a-fA-F]+)(?:\s*#.*)?$')


def read_symbol_conversion_info(file_path: str | PathLike, encoding: str = "utf-8") -> SymConversionInfo:
    offsets = []
    additions = []
    deletions = set()

    with open(file_path, "r", encoding=encoding) as f:
        for line in map(str.strip, f):
            if len(line) == 0:
                continue
            if line[0] == "#":
                continue

            match = __OFFSET_PATTERN.match(line)

            if match:
                offsets.append(SymbolOffset(
                    address=int(match.group(1), 0),
                    offset=int(match.group(2), 0)
                ))
                continue

            match = __ADDITION_PATTERN.match(line)

            if match:
                additions.append(SymbolAddition(
                    address=int(match.group(1), 0),
                    name=match.group(2)
                ))
                continue

            match = __DELETION_PATTERN.match(line)

            if match:
                deletions.add(int(match.group(1), 0))
                continue

            raise ValueError(f'Malformatted symbol conversion rule: "{line}"')

    offsets.sort(key=lambda o: o.address)

    return SymConversionInfo(offsets=offsets, additions=additions, deletions=deletions)


########################################################################################################################

if __name__ == '__main__':
    __main()
