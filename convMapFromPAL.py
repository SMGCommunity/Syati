# All target regions
REGIONS = ["PAL", "USA", "JAP", "KOR", "TWN"]

# First, we define the offsets that we have to apply to some symbols to get the proper addresses in the other regions.
# All of these offsets are relative to the symbol's location in the PAL map. For PAL, USA and JAP, all the code lines up
# 1:1, however, the data and static data addresses are different due to the ErrorMessageArchive having different sizes
# in all regions.
# For the time being, KOR and TWN are not supported, because their code sections differ at some points as well. However,
# I'm still researching the offsets, so these will be supported in the future.
# Each entry is a pair consisting of the starting PAL address to apply an offset to and the offset to apply to all the
# symbol addresses.
USA_OFFSETS = [
    (0x806599A0, -0x5700)  # After ErrorMessageArchive
]

JAP_OFFSETS = [
    (0x806599A0, -0x5F20),  # After ErrorMessageArchive
    (0x8072DD80, -0x5F40)  # BSS Start
]

KOR_OFFSETS = [
    # Todo: Finish up KOR offsets
    (0x8047B110, 0x10),
    (0x80492340, 0x50),
    (0x80494AA0, 0x70),
    (0x804BD390, 0x90),
    (0x8054B440, 0x100),
    # there is more here
    (0x80643D20, 0x580),  # Data start
    (0x8064CBB0, 0x590),  # After language-related table
    (0x8064CF12, 0x5A0),  # After language ID table
    (0x806599A0, -0x68C0),  # After ErrorMessageArchive
    # there is more here
    (0x8072DD80, -0x4E60)  # BSS Start
]

TWN_OFFSETS = [
    # Todo: Investigate and populate TWN offsets
]

# Stores current offset information for all non-PAL regions. Each element is a list of three values. First is the offset
# to apply to addresses, second is the next index into the offsets table and third is the offsets table.
CUR_OFFSET_INFO = {
    "USA": [0x0, 0, USA_OFFSETS],
    "JAP": [0x0, 0, JAP_OFFSETS],
    "KOR": [0x0, 0, KOR_OFFSETS],
    "TWN": [0x0, 0, TWN_OFFSETS]
}


# This function goes through all regions and tries to find the next offset to apply to symbol addresses. If a new offset
# has been found, the current offset info for the corresponding region will be updated.
def try_advance_offsets(address: int):
    for region in REGIONS:
        # PAL is used as the base, so we do not have to calculate offsets for that region
        if region == "PAL":
            continue

        offset_info = CUR_OFFSET_INFO[region]
        _, next_index, all_offsets = offset_info

        if next_index >= len(all_offsets):
            continue

        next_off_address, next_offset = all_offsets[next_index]

        if address >= next_off_address:
            offset_info[0] = next_offset
            offset_info[1] = next_index + 1


# Returns the offset to apply to addresses for the specified target region
def get_offset(region: str) -> int:
    return CUR_OFFSET_INFO[region][0]


# Stores all the symbols and their addresses for each target region
SYMBOLS = {
    "PAL": list(),
    "USA": list(),
    "JAP": list(),
    "KOR": list(),
    "TWN": list(),
}

# Read all symbols from the MAP file, adjust their offsets and append them to the respective symbol lists. Note that
# this script was designed specifically for IDA map files. I'm pretty sure that Ghidra uses a different format so these
# are very likely not compatible with this.
with open("SB4P01.map", "r") as f:
    found_addresses = False
    is_data = False

    for line in f:
        line = line.strip("\n")

        # First of all, we have to find the start of addresses. The header is always the same, so we look for its
        # contents.
        if not found_addresses and "Publics by Value" in line:
            found_addresses = True
            continue
        # Skip any non-symbol line
        if not found_addresses or not line.startswith(" "):
            continue

        # Get address and symbol from line
        address_str, symbol = line[6:].split("       ")
        address_int = int(address_str, 16)

        # Discard nullsubs, defs and jumps
        if symbol.find("nullsub") == 0 or symbol.find("def_") == 0 or symbol.find("j_") == 0:
            continue

        # "sub" has been renamed to "subtract" since sub is used as a special keyword in IDA. We have to take this into
        # account and rename corresponding symbols.
        if symbol.find("subtract") != -1:
            symbolr = symbol.split("__")[1]
            symbol = f"sub__{symbolr}"

        # Treat and filter data symbols differently. Most of the time, we remove useless data such as strings
        if is_data:
            # Replace __vtbl__ with __vt__
            if symbol.startswith("__vtbl__"):
                symbol = f"__vt__{symbol[8:]}"
            # Keep static instances, objects, etc.
            elif "__" in symbol:
                pass
            # Discard useless data
            else:
                continue

        # "__DBEXIWriteRam" is the last function symbol in SMG2. After this comes all data
        if address_int > 0x80643C38:
            is_data = True

        # Try to advance the offsets for all regions
        try_advance_offsets(address_int)

        for region in REGIONS:
            if region == "PAL":
                symbol_str = f"{symbol}=0x{address_str}\n"
            else:
                symbol_str = f"{symbol}=0x{address_int + get_offset(region):08X}\n"

            SYMBOLS[region].append(symbol_str)


# Write all symbol files
for region in REGIONS:
    # Exclude KOR and TWN for now
    if region == "KOR" or region == "TWN":
        continue

    with open(f"symbols/{region}.txt", "w") as f:
        for line in SYMBOLS[region]:
            f.write(line)
