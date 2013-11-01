#!/usr/bin/perl

$num = 0;
$file = "perl.file";
open WR, '>>', $file;
while($num != 1000000){
	print WR "sddddddddd\n";
	$num += 1;
}
