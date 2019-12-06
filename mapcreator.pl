# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mapcreator.pl                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iromero- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/23 16:33:10 by iromero-          #+#    #+#              #
#    Updated: 2019/09/23 16:33:18 by iromero-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#!/usr/bin/perl
use warnings;
use strict;
die "program x y density" unless (scalar(@ARGV) == 3);
my ($x, $y, $density) = @ARGV;
print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
for (my $j = 0; $j < $x; $j++) {
if (int(rand($y) * 2) < $density) {
print "o";
}
else {
print ".";
}
}
print "\n";
}
