sub adjustHeap{
	my ($p,$len) = @_;
	my $i, $j;
	my $tmp;
	$i = $p*2+1;
	while ($i<$len) {
		if ($i +1 < $len) {
			$j = ($ar[$i]>=$ar[$i+1]?$i:$i+1);
		}else {
			$j = $i;
		}
		if ($ar[$p] >= $ar[$j]) {
			return;
		}else {
			$tmp = $ar[$p];
			$ar[$p] = $ar[$j];
			$ar[$j] = $tmp;	
		}
		$i=$j*2+1;
		$p = $j;

	}	
}

$in = $ARGV[0];
local @ar = split(" ", $in);

my $len = @ar;
my $i, $tmp;

for ($i=$len/2-1; $i>=0;$i--) {
	adjustHeap($i, $len);
}
$tmp = $ar[0];
$ar[0] = $ar[$len-1];
$ar[$len-1] = $tmp;
for ($i=$len-1; $i>0;$i--) {
	adjustHeap(0, $i);
	$tmp = $ar[0];
	$ar[0] = $ar[$i-1];
	$ar[$i-1] = $tmp;

}

foreach $tmp (@ar) {
	print "$tmp, ";

}
print "\n";
