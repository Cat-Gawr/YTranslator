print "#ifndef UNICODE_SCRIPT_DATA_H_\n";
print "#define UNICODE_SCRIPT_DATA_H_\n";
print "namespace sentencepiece {\n";
print "namespace unicode_script {\n";
print "namespace {\n";
print "void InitTable(std::unordered_map<char32, ScriptType> *smap) {\n";
print "  CHECK_NOTNULL(smap)->clear();\n";

while (<>) {
  chomp;
  if (/^([0-9A-F]+)\s+;\s+(\S+)\s+\#/) {
    printf("  (*smap)[0x%s] = U_%s;\n", $1, $2);
  } elsif (/^([0-9A-F]+)\.\.([0-9A-F]+)\s+;\s+(\S+)\s+\#/) {
    printf("  for (char32 c = 0x%s; c <= 0x%s; ++c)\n", $1, $2);
    printf("    (*smap)[c] = U_%s;\n", $3);
  } else {
    next;
  }
}

print "}\n";
print "}  // namespace\n";
print "}  // namespace unicode_script\n";
print "}  // namespace sentencepiece\n";
print "#endif  // UNICODE_SCRIPT_DATA_H_\n";
