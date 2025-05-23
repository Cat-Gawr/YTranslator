use strict;
use warnings;

sub Process() {
  my $file = shift @_;
  if ($file =~ /\.h$/) {
    print "$file\n";
  }
  return unless open(F, $file);
  my @files = ();
  while (<F>) {
    chomp;
    if (/\#include <(google\/protobuf\/[^>]+)>/) {
      push @files, $1;
    }
  }
  close(F);
  for my $file (@files) {
    &Process($file);
  }
}

for my $f (@ARGV) {
  &Process($f);
}
