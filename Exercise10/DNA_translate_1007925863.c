////////////////////////////////////////////////////////////
// CSC A48 - DNA alignment Pt. 1
//
// The goal of this assignment is to write a function that
// translates tripled (sets of 3) DNA nucleotide bases to
// the corresponding aminoacid.
//
// As a brief review of your Biology lessons, DNA is a double
// stranded chain of nucleic-acids, there are 4 types of
// nucleotides denoted by the letters:
//
// A, C, T, G
//
// The sequence of these nucleotides specifies the sequence
// in which aminoacids (the building blocks of proteins)
// are assembled into every single one of the proteins that
// make up the cells of most licing things (there are a 
// few that do not use DNA, opting instead to use the single
// stranded version called RNA, viruses tend to be sneaky
// that way!)
//
// Each set of 3 nucleotides specifies one aminoacid in
// a protein's specification.
//
// The goal of this exercise is for you to write a small
// function that takes in a DNA sequence (a string made up
// of letters ATCG in some sequence) and determines the
// corresponding sequence of aminoacids. Below, you will
// find a table listing each aminoacid, and the sequences
// of DNA nucleotides that specify that aminoacid.
// 
// Note that many aminoacids can be specified by more than
// one input!
//
//  Aminoacid   Single letter name	Inputs
//  Isoleucine 		I 		ATT, ATC, ATA
//  Leucine 		L 		CTT, CTC, CTA, CTG, TTA, TTG
//  Valine 		V 		GTT, GTC, GTA, GTG
//  Phenylalanine 	F 		TTT, TTC
//  Methionine 		M 		ATG
//  Cysteine 		C 		TGT, TGC
//  Alanine 		A 		GCT, GCC, GCA, GCG
//  Glycine 		G 		GGT, GGC, GGA, GGG
//  Proline 		P 		CCT, CCC, CCA, CCG
//  Threonine 		T		ACT, ACC, ACA, ACG
//  Serine 		S 		TCT, TCC, TCA, TCG, AGT, AGC
//  Tyrosine 		Y 		TAT, TAC
//  Tryptophan 		W 		TGG
//  Glutamine 		Q 		CAA, CAG
//  Asparagine 		N 		AAT, AAC
//  Histidine 		H 		CAT, CAC
//  Glutamic acid 	E 		GAA, GAG
//  Aspartic acid 	D 		GAT, GAC
//  Lysine 		K 		AAA, AAG
//  Arginine 		R 		CGT, CGC, CGA, CGG, AGA, AGG
//
//  Your task is to determine whether two DNA sequences use the
//  same number of each type of aminoacid (the order of the
//  amino-acids doesn't matter here).
//  To that end, you need to write a function that
//  takes a DNA sequence and converts it to the corresponding
//  sequence of aminoacids, for instance if the input sequence is:
//
//  AAGGAGTGTTTT
//
//  Your function must return
//
//  KECF
//
//  Then you need to write a function that takes in two DNA
//  sequences and determines whether they produce the same
//  numbers of each aminoacid. For example, if the sequence
//  of aminoacids for each of the input DNA sequences is
//
//  AATVKFAA    and    TAAVKAAF
//
//  The function must return 1 (they produce the same number
//  of each aminoacid). However, if the aminoacid sequences
//  are
//
//  TVFAAKVV    and    ECVAATFK
//
//  the function will return 0 (not the same number of each
//  aminoacid).
//
// (c) F. Estrada, March, 2022
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void DNA_sequencing(char inputDNA[1024], char outputAminoAcids[1024])
{
    // This function receives two strings, one that contains a sequence
    // of DNA nucleotides (which MUST be composed of the letters
    // ACGT, no spaces or other symbols can appear here!), and
    // updates an initially empty string 'outputAminoAcids' with the
    // sequence of aminoacids corresponding to the input DNA sequence
    //
    // Try to make this function as compact (fewer lines of code, more
    // elegant, easier to read code) as possible. APply what you've
    // learned in Exercises 6-8, all of which helped you practice
    // using strings!
    //int i = 0;
    //char input[4];
    int len = strlen(inputDNA);
    
    len = len/3;
    int index = 0;

    for (int i = 0; i < len; i++)
    {
        char input[4] = {inputDNA[index], inputDNA[index+1], inputDNA[index+2], '\0'};

        // printf("input: %s  i: %d \n", input, i);

        if (strcmp(input, "ATT") == 0 || strcmp(input, "ATC") == 0 || strcmp(input, "ATA") == 0)
        {
            outputAminoAcids[i] = 'I';
        }
        else if (strcmp(input, "CTT") == 0 || strcmp(input, "CTC") == 0 || strcmp(input, "CTA") == 0 || strcmp(input, "CTG") == 0 || strcmp(input, "TTA") == 0 || strcmp(input, "TTG") == 0)
        {
            outputAminoAcids[i] = 'L';
        }
        else if (strcmp(input, "GTT") == 0 || strcmp(input, "GTC") == 0 || strcmp(input, "GTA") == 0 || strcmp(input, "GTG") == 0)
        {
            outputAminoAcids[i] = 'V';
        }
        else if (strcmp(input, "TTT") == 0 || strcmp(input, "TTC") == 0)
        {
            outputAminoAcids[i] = 'F';
        }
        else if (strcmp(input, "ATG") == 0)
        {
            outputAminoAcids[i] = 'M';
        }
        else if (strcmp(input, "TGT") == 0 || strcmp(input, "TGC") == 0)
        {
            outputAminoAcids[i] = 'C';
        }
        else if (strcmp(input, "GCT") == 0 || strcmp(input, "GCC") == 0 || strcmp(input, "GCA") == 0 || strcmp(input, "GCG") == 0)
        {
            outputAminoAcids[i] = 'A';
        }
        else if (strcmp(input, "GGT") == 0 || strcmp(input, "GGC") == 0 || strcmp(input, "GGA") == 0 || strcmp(input, "GGG") == 0)
        {
            outputAminoAcids[i] = 'G';
        }
        else if (strcmp(input, "CCT") == 0 || strcmp(input, "CCC") == 0 || strcmp(input, "CCA") == 0 || strcmp(input, "CCG") == 0)
        {
            outputAminoAcids[i] = 'P';
        }
        else if(strcmp(input, "ACT") == 0 || strcmp(input, "ACC") == 0 || strcmp(input, "ACA") == 0 || strcmp(input, "ACG") == 0)
        {
            outputAminoAcids[i] = 'T';
        }
        else if(strcmp(input, "TCT") == 0 || strcmp(input, "TCC") == 0 || strcmp(input, "TCA") == 0 || strcmp(input, "TCG") == 0 || strcmp(input, "AGT") == 0 || strcmp(input, "AGC") == 0)
        {
            outputAminoAcids[i] = 'S';
        }
        else if(strcmp(input, "TAT") == 0 || strcmp(input, "TAC") == 0)
        {
            outputAminoAcids[i] = 'Y';
        }
        else if(strcmp(input, "TGG") == 0)
        {
            outputAminoAcids[i] = 'W';
        }
        else if(strcmp(input, "CAA") == 0 || strcmp(input, "CAG") == 0)
        {
            outputAminoAcids[i] = 'Q';
        }
        else if(strcmp(input, "AAT") == 0 || strcmp(input, "AAC") == 0)
        {
            outputAminoAcids[i] = 'N';
        }
        else if(strcmp(input, "CAT") == 0 || strcmp(input, "CAC") == 0)
        {
            outputAminoAcids[i] = 'H';
        }
        else if(strcmp(input, "GAA") == 0 || strcmp(input, "GAG") == 0)
        {
            outputAminoAcids[i] = 'E';
        }
        else if(strcmp(input, "GAT") == 0 || strcmp(input, "GAC") == 0)
        {
            outputAminoAcids[i] = 'D';
        }
        else if(strcmp(input, "AAA") == 0 || strcmp(input, "AAG") == 0)
        {
            outputAminoAcids[i] = 'K';
        }
        else if(strcmp(input, "CGT, CGC, CGA, CGG, AGA, AGG") == 0 || strcmp(input, "CGC") == 0 || strcmp(input, "CGA") == 0 || strcmp(input, "CGG") == 0 || strcmp(input, "AGA") == 0 || strcmp(input, "AGG") == 0)
        {
            outputAminoAcids[i] = 'R';
        }

        index = index + 3;
    }
}

int amino_matching(char inputDNA1[1024], char inputDNA2[1024])
{
    // This function receives two strings representing DNA
    // sequences. It returns 1 if the sequences produce the
    // same number of each type of aminoacid. Think carefully
    // about the best (simplest?) way to to this.


    char str1[1024];
    char str2[1024];

    int len1 = strlen(inputDNA1);
    int len2 = strlen(inputDNA2);
    char temp = ' ';

    strcpy(str1, inputDNA1);
    strcpy(str2, inputDNA2);

    if (len1 != len2)
        return 0;

    for (int i = 0; i < len1-1; i++)
    {
        for (int j = 0; j < len1-i-1; j++)
        {
            if (str1[j] > str1[j+1])
            {
                temp = str1[j+1];
                str1[j+1] = str1[j];
                str1[j] = temp;
            }
        }
    }

    for (int i = 0; i < len1-1; i++)
    {
        for (int j = 0; j < len1-i-1; j++)
        {
            if (str2[j] > str2[j+1])
            {
                temp = str2[j+1];
                str2[j+1] = str2[j];
                str2[j] = temp;
            }
        }
    }


    if (strcmp(str1, str2) == 0)
        return 1;
    


    return 0;
}

#ifndef __testing

int main()
{
	char DNAseq1[1024]="CTTATTGTTCCAATGTGGCGGCACTACACGTGCGTTATC";
	char DNAseq2[1024]="ATTTATTGTACATATCATCGTTGGATGCCCGTAATATTG";
        char DNAseq3[1024]="ATCGTTTGCACGTACCACCGGTGGATGCCAGTTATTCTT";
	char aminoAcids[1024]="";

	printf("Input DNA sequence 1: %s\n",DNAseq1);
	DNA_sequencing(DNAseq1,aminoAcids);
	printf("Output aminoacid sequence 1: %s\n",aminoAcids);

	printf("Input DNA sequence 2: %s\n",DNAseq2);
	DNA_sequencing(DNAseq2,aminoAcids);
	printf("Output aminoacid sequence 2: %s\n",aminoAcids);

	printf("Input DNA sequence 3: %s\n",DNAseq3);
	DNA_sequencing(DNAseq3,aminoAcids);
	printf("Output aminoacid sequence 3: %s\n",aminoAcids);

	if (amino_matching(DNAseq1,DNAseq2)==1)
	{
		printf("Sequence 1 matches sequence 2 in aminoacids\n");
	}
	else
	{
		printf("Sequence 1 does not match sequence 2 in aminoacids\n");
	}

	if (amino_matching(DNAseq1,DNAseq3)==1)
	{
		printf("Sequence 1 matches sequence 3 in aminoacids\n");
	}
	else
	{
		printf("Sequence 1 does not match sequence 3 in aminoacids\n");
	}

	if (amino_matching(DNAseq2,DNAseq3)==1)
	{
		printf("Sequence 2 matches sequence 3 in aminoacids\n");
	}
	else
	{
		printf("Sequence 2 does not match sequence 3 in aminoacids\n");
	}

	return 0;
}

#endif
