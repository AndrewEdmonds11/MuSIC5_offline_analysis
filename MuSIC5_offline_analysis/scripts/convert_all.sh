# convert the listed files to a useable root format
#

fileids=( 451 452 455 458 459 )
notes=( "0.5mm" "0.5mm" "1mm" "5mm" "5mm" )

exe="../mid2root_converter"
in_file_dir="../../../MuSIC_data_0.5Cu/"
out_file_dir="../../../converted_data/"
preffix="run00"
file_suffix=".root"
log_file=$out_file_dir"log.log"
notes_file=$out_file_dir"notes.txt"

len=${#fileids[@]}

gitcommit="$(git log --pretty=format:'%h' -n 1)" || gitcommit="not_commited"
gitbranch="$(git symbolic-ref HEAD 2>/dev/null)" || gitbranch="unnamed_branch"
gitbranch=${gitbranch##refs/heads/}

# standard header
header="#\n\
# This is an autogenerated header, do not modify it\n\
# Git commit:\t [$gitbranch $gitcommit]\n\
# Generated on:\t $(date)\n\
#\n"

echo -r $header >> $notes_file

echo -e "File \t\t degarder \t target" >> $notes_file
for (( i = 0; i < ${len}; i++ ));
do
	infile=$in_file_dir$preffix${fileids[i]}$file_suffix
	outfile=$out_file_dir$preffix${fileids[i]}"_converted"$file_suffix
	echo $exe -i $infile -o $outfile -a  
	echo $exe -i $infile -o $outfile -a >> $log_file
	$exe -i $infile -o $outfile -a >> $log_file
	echo -e $preffix${fileids[i]}"\t" ${notes[i]} "Aluminium \t 0.5mm Copper" >> $notes_file
	echo >> $log_file
	chmod u-w $outfile
done;
chmod u-w $notes_file