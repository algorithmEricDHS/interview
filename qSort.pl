sub partition {
	my ($low, $high) = @_;
	my $p = $init[$low];
	while ($low < $high) {
		while ($init[$high]>=$p && ($low<$high)) {
			$high--;
		}
		$init[$low] = $init[$high];
		while ($init[$low] <= $p && ($low < $high)) {
			$low++;
		}
		$init[$high] = $init[$low];
		
		  
	} 
	$init[$low]  = $p;
	print "partition loc is $low\n";
	return $low;
}
sub qSort {
	my ($low, $high) = @_;
	print ("low is $low, high is $high\n");
	if ( $low>=$high ) {
		return 0;
	}
	my $p = partition ($low, $high);
	qSort($low, $p);
	qSort($p+1, $high);

}

my $in = $ARGV[0];
local @init = split(" ", $in);
my $len = @init;
print ("length is $len\n");
qSort(0, $len-1);
foreach $s (@init) {
	print "$s, ";
}
print "\n";
