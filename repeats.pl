if (@ARGV != 1) {
	print "ARG error\n";
	exit -1
}

$s = $ARGV[0];
chomp ($s);
print $s."\n";

my %re={};

my $key;
while ($s =~ /([\w\d]+)[\W]+([\w\W\d)]+)/) {
	$key = $1;
	print "key is $key, rest of string is: $2\n";
	$s = $2;
	if (exists $re{$key} ) { 
		$re{$key}++;
	}
	else {
		$re{$key} = 1;
	}
}
if (length($s) > 0) {
	if ( exists $re{$s}) { 
		$re{$s}++;
	} 
        else {
		$re{$s} = 1;
	}
}

foreach $key (keys(%re)) {
	print "key: $key, times: $re{$key} \n";

}

