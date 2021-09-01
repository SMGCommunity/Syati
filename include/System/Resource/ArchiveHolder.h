#pragma once

class JKRArchive;

class ArchiveHolder
{
public:
    JKRArchive* getArchive(const char *) const;
};