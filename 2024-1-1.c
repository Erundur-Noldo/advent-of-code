/* advent of code 2024, 1.1 */
/* I could have done this with my dlist library.... but oh well */

#include <stdio.h>
#include <stdlib.h>


int list_one[] = {66845,94793,76946,27374,47847,83270,19354,69716,16902,51817,40758,39074,34632,64980,96137,55489,95130,50275,46438,34182,99196,28426,55782,96554,92781,66818,83432,92511,87928,45552,60234,34717,17406,29863,30715,79985,19498,45577,22430,60651,24435,47805,21747,42759,81798,69888,10983,58312,86884,84419,18170,18387,30887,27509,79888,84877,37741,56232,66360,35077,11529,83449,65777,92759,36784,44166,27169,47337,58412,44195,86636,30002,92886,47608,93286,95162,28232,36024,79729,46188,36793,43516,20294,39704,12801,29338,87398,43037,48777,73934,63516,91790,86093,80995,18788,55112,50558,50125,70970,95693,17814,94946,28046,41708,94045,43687,61579,40428,22420,81816,46315,13240,14096,74231,65623,93360,23203,62141,78614,25431,40555,69148,59262,69333,44889,75646,96536,52772,89647,15843,96124,44307,26300,51312,80629,33658,82408,58384,96798,39019,53075,90232,70094,29829,22687,36509,65164,97198,94559,23976,68670,35761,89859,87196,93726,25588,82420,39195,18964,76776,81228,48337,35288,31186,62040,82769,75516,46916,77933,92256,32048,31355,81356,29014,40593,67982,57605,59621,71053,58788,96408,21328,60042,26150,36476,98875,50224,13099,24240,14259,25943,69018,64982,56462,18046,78056,34273,51578,28229,19334,74063,64637,63440,69596,44661,83603,47360,38361,30109,54979,57864,11404,31046,42983,82072,93495,14189,36367,99522,26894,20066,51211,75520,66473,41955,26371,73611,23686,85473,91840,64262,16860,89770,25598,80127,91437,68177,38952,24402,47962,35661,92555,46076,21462,77271,81010,22322,54671,42034,61234,11778,73064,92302,88810,28987,19948,46165,80483,10186,50266,38661,43071,29149,20786,41543,65554,38133,83184,81455,50181,21588,71901,56580,92298,12615,54771,40608,74661,74667,91093,78147,88520,83147,32466,88003,48870,57990,25924,28398,59394,88485,24797,20403,41703,98485,20982,89943,90090,48506,73724,16518,80097,17726,55319,31484,95079,51136,20432,36397,60587,97583,79660,90931,68754,81332,36693,83807,69967,42871,95094,99212,44058,80641,88334,88355,23565,64119,17173,28557,55707,60573,78740,25688,61756,42962,29631,94426,98512,68213,89436,52114,50779,37430,41985,18966,46251,77421,61790,74498,69841,65897,41449,48907,81437,59295,83332,72986,96096,61423,17994,61296,88163,54306,95733,99042,68770,88129,33732,77286,90425,15280,31735,52247,30396,99667,51830,83666,86580,85254,42725,23687,22760,46614,72811,54977,29431,18885,36487,89636,35161,81599,88407,22435,79005,57331,22158,96696,70561,73421,61118,42519,43521,63402,45694,76105,62478,12358,86440,87086,53389,85805,67650,15685,58192,47818,11074,71914,93767,15245,61703,98920,39398,24806,95455,31836,75823,76495,30421,29524,87652,28324,76379,21066,48616,27230,72632,68412,93254,58582,49794,47461,76885,64004,32657,53863,20628,91608,75577,71476,81995,50925,11299,35420,10331,15779,85678,91928,63346,66976,83382,57567,57699,87134,75545,25631,87276,56940,84938,95193,29270,89353,40688,66751,66452,38862,96222,87343,46164,99417,70060,71154,12509,93651,71299,10832,52974,40981,29705,67938,60177,47250,54643,85588,98925,60422,24036,29403,74173,55986,25014,12619,94185,36302,80587,69768,69155,50416,46304,96705,28345,77293,12724,35375,75160,46386,39994,91271,29612,41036,81721,17164,59045,47643,88393,84088,59047,78516,15157,43690,75594,44896,94548,83041,96815,32828,58699,31287,26029,65166,54211,83286,56093,72216,41450,40073,95257,45206,77156,95757,37072,64269,32134,17176,96935,12632,58840,45556,56436,63022,58109,20092,94565,95740,82012,95332,10057,90826,26656,21477,69198,86852,99374,67436,69091,98680,62432,81423,65121,63197,61748,48450,22248,53155,66777,61747,77640,30701,77911,68586,16193,87617,30286,37535,33511,13847,48968,18649,90213,19938,45563,65848,15964,46068,42958,75671,29655,22699,51147,94306,25877,65736,90797,37067,83464,42197,91306,60911,34318,38793,27850,14650,91128,32458,54600,98050,86045,42279,42179,74312,79748,40215,41710,30328,26336,36852,40112,85174,71517,67431,43343,13731,13807,67892,27164,73866,49004,30611,99434,39641,37656,31848,98478,98613,82739,90600,11405,38095,78900,90011,83200,71310,29261,99897,10080,53548,33783,13126,19067,60524,78024,78854,45049,99076,38748,10930,59839,78585,59376,60726,81844,53820,58200,39265,60470,91160,27028,47223,76737,57526,65236,53301,24915,35708,95380,84774,41172,91822,40133,12658,68683,48857,75612,68638,50216,99960,84452,45383,75492,13480,50803,54012,84902,17970,11010,99306,40510,49829,59557,85594,59545,20954,12472,70813,99797,77207,49923,65898,37494,85492,39497,36089,20089,96255,32410,48216,76597,53910,15354,98751,74557,86473,57086,69351,49032,95909,98841,38404,53132,41823,73232,14338,20654,39466,17828,44233,75537,97545,16764,17017,70260,85468,37966,49722,55689,47330,94724,28441,27435,49740,34057,64654,83242,97554,42324,43064,64801,55649,71147,90522,39447,26012,12500,96913,73053,96929,17234,71663,27255,20631,53872,21030,63642,37041,62151,44779,33142,34298,74521,97108,77170,82868,60362,66295,18853,86177,24054,64974,88395,24079,90673,28410,23503,22127,43022,21423,20584,19793,85494,35760,37390,11337,52314,99221,90131,79699,22197,21685,61808,95453,66322,49172,54628,87270,25855,18455,45453,48577,47391,32796,36667,24640,52237,10472,96200,48162,31265,28125,73922,32255,47397,47401,70327,38692,18472,71218,37097,79607,88691,30767,47670,87223,62459,35995,39905,62948,14137,51968,19454,48128,87280,97139,91913,52926,88930,51402,56326,56973,30330,56823,43407,86434,16605,24931,58345,25412,90343,20577,19871,33550,30768,44985,93435,17474,33032,67655,11189,76696,81827,14652,78881,49434,16136,95899,52886,75680,25008,10532,70853,97765,77075,49731,12421,13995,13459,44822,45941,84375,68154,50838,57673,89564,86616,95622,95036,69957,68179,11978,89856,43029,30680,65119,61868,28887,30237,74565,52029,53311,28179,25996,21527,40311,77116,32339,51922,39858,42050,22499,40666,49779,57894,21691,29904,73894,25080,24284,62787,82576,90992,56542,93368,97106,95744,86470,15426,67124,93975,20387,98213,58271,26911,18479,10735,27321,49224,38905,81499,50470,25745,85084,36196,43825,11678,63510,15304,13540,95310,64421,14821,29117,22026,66744,73205,13305,47886,16515,86124,30895,69966,31783,97288};
int list_two[] = {37619,99076,36179,48777,92154,97857,94331,58559,36957,88003,64262,90635,79874,96787,94559,98589,76776,50416,49722,49722,51678,49456,77278,38327,25688,64897,67261,85918,74826,37494,58251,40758,40666,13598,16605,24806,33371,59103,97187,52438,14715,33629,21255,37159,25688,75513,57175,51968,41517,46068,76776,30282,51117,49568,65951,31605,70988,51993,34958,60422,96255,21189,39047,70579,34261,77293,46068,15975,48777,71990,25688,64342,31836,76776,93216,72607,49722,42759,44744,90896,40758,69333,69351,65846,75185,69351,33648,40666,48777,51968,67431,94559,50924,95426,69351,58623,51968,48777,65082,34007,75466,34672,18149,92261,40666,64262,48777,60422,32085,40758,42253,48777,50416,98724,29631,51968,13106,96255,44089,25688,37905,67431,72776,40758,40666,80493,65674,55418,40758,14319,10675,65041,19974,78939,88003,72722,51968,40362,51968,64262,69333,81066,84299,64262,30237,31836,49722,73460,32258,75804,45453,33638,30972,48777,73290,40666,68892,66867,26674,45413,60422,92298,50416,94774,83156,40666,52772,83286,62114,68878,67431,92298,81828,64443,76965,92627,77293,23426,15293,33577,15826,16605,38036,16605,45576,26150,26150,77512,57493,36228,71801,15570,29117,42759,40666,26150,50416,73053,51968,81510,22991,99076,96255,90956,60422,73568,25240,56084,49115,49722,76776,23775,84459,63211,21091,31277,73053,50416,29631,44711,12397,69351,71791,41543,76776,45285,51968,46068,60422,30237,35142,48543,81829,48534,48777,23375,25777,90058,46233,16605,77293,69333,73053,50298,20126,71068,51968,16605,43993,16605,48777,96914,66267,39985,49722,63051,42759,32007,87088,98182,60422,29117,90127,92298,63002,44245,50446,43685,30237,20015,41543,77005,67190,30290,43868,97825,83376,81327,27063,69333,74050,67431,58241,96255,26594,44355,33895,52335,25688,16605,18070,94556,92298,25688,39009,71267,90424,84500,75682,15460,51968,85128,30691,76440,40758,69351,69333,50416,81701,87382,69333,79014,61415,99076,29631,18053,63785,41543,98738,91288,99076,84467,34674,29631,71891,64262,54463,36522,31472,49080,53380,48777,40758,50713,94559,92298,67431,82316,69351,29117,74278,18690,18749,87256,73331,69146,78181,45476,10793,82893,20462,29160,44418,40758,67431,89658,37494,50416,41543,96255,15425,59232,51570,61049,15221,71427,69333,92099,61983,60422,46859,70146,13562,40758,30237,79901,25524,98750,48777,11056,97931,94009,77846,24806,49722,73999,40666,64262,50324,49495,67431,33080,50416,10940,41543,40666,30237,45453,60631,43928,79091,64262,15989,95467,44778,68359,99076,88199,83286,39542,31836,68375,63010,46795,92298,94986,40666,14418,79805,69333,26347,43675,93670,83582,42759,89112,95693,64262,69542,26150,60422,22670,20848,71126,73053,73053,69333,71387,40758,41543,60562,14543,73230,96255,10455,35993,87804,69351,64262,23722,69351,77938,99076,29117,75594,37494,42759,75594,96255,88003,44223,13304,99196,76776,41543,10800,51968,42251,54917,34604,63191,42759,53340,16819,17153,46438,57690,57572,27010,10746,34499,48869,78940,73847,30237,64262,11346,40758,95118,49969,91132,25688,76776,69333,90370,39886,40758,25688,40758,69333,88003,66972,76776,47593,39980,11763,78224,16273,69351,35177,10590,52945,78625,45453,65833,48140,59925,77293,88472,69333,69333,55408,48777,31836,29471,99076,76776,99196,94559,53479,71111,39265,42184,51415,70721,81992,64262,37494,83286,99076,91733,73053,58645,27606,49722,78671,57288,16605,87915,43889,43521,94350,28044,16605,39455,64262,60422,23521,10638,65191,51968,87895,67431,14463,76776,36067,85685,37494,28483,30835,31534,40666,26735,37640,31836,46068,37494,49722,92795,89795,41543,50416,29214,83286,30639,31836,73053,39784,93617,95734,94302,81591,95903,95693,94086,92039,81319,51247,14934,77293,83368,74755,23448,13602,27217,51968,25688,42589,42759,30237,73053,16605,95623,91292,45801,99076,92298,33706,96334,37433,64262,64339,98055,62677,75988,41543,19215,41543,39080,67431,77293,90776,68060,88003,22273,16836,16605,32703,99004,64262,22989,54987,39600,13761,29117,11308,79799,64262,96255,46551,30237,83598,17687,36729,41659,52772,26098,49223,64515,65037,31350,29631,41543,60422,22585,94884,76776,48777,31565,69351,66750,47031,25688,81291,57953,26241,86796,49722,60127,97760,37832,51968,60422,33170,96442,85013,41543,16605,56760,31836,85609,16605,83286,27448,28106,68961,90839,50910,69351,61451,43558,40666,84502,77750,58184,13882,49722,60195,22237,84944,60422,96255,76776,86694,49722,64262,88882,60358,67431,67431,40666,78637,89650,81151,49160,51618,30237,24806,83863,37494,14785,42979,96255,46438,96255,54602,18651,14547,90551,90793,64457,86585,16557,10281,64037,26150,25688,48777,99294,16605,74560,61132,77293,99107,42759,82505,60422,51968,43797,61407,30237,64262,63390,41072,53047,60422,63752,25688,11717,27423,71907,29117,73053,69351,47040,40758,48777,41347,60422,28206,92655,21088,96255,21102,64262,49722,69333,61341,42759,89055,42759,92298,13379,99076,44361,70645,99076,71083,42956,40666,54524,38781,14324,92189,76776,49722,22099,26150,52772,26493,60422,41005,81692,69046,30237,99347,64262,29631,67431,11112,67225,25688,92298,76776,57892,89226,53250,13618,30237,46438,59373,40323,67431,69351,75737,75723,39690,56849,55399,27839,92298,62652,65480,40686,27800,87629,99076,90954,48777,73220,38154,60422,19213,31836,35466,33313,49008,16605,19624,88003,15008,74801,76776,51968,16651,97229,25688,77293,29631,46179,29631,51492,66255,41045,13749,16605,31836,40666,39962,69225,45453,27225,27332,67854,61629,95693,84501,64775,73053,48777,96255,69530,83436,27464,77293,25688,29631,37289,41543,35379,40758,37494,99076,49722,59071,18424,45453,67108,41543,98528,45588,81360,20115,67635,20506,40758,46068,27538,85083,43557,10626,45453,16605,38065,76776,32072,23791,12649,33383,91350,51344,77293,89141,92298,45124,51153,81204,45453,67537,88003,88003,64262,43982,52772,41543,33920,40777,75657,48777,34518,67431,25688,79235,47224,41543,58837,96255,21575,25688,48777,96422,75594,42303,92298,29117,80395,57449,31836,60721,48788,99076,49722,42759,16605,45630,15623,29434,41944,95159,67431,42915,14222,72474,52772,25688,40758,88003,76776,89841,33570,36521,72863,60422,15634,59541,77004,46438,25582,85509,51968};



void bubblesort(int *a, int size) {
	/* copied and edited from dlist.c */
	for(int i=size - 1; i>0; i--) {
        for(int j=0; j<i; j++) {
            if(a[j] > a[j+1]) {
            	int buffer = a[j];
            	a[j] = a[j+1];
            	a[j+1] = buffer;
            }
        }
    }

    return;

}


int main() {
	int list_size = sizeof(list_one)/sizeof(*list_one);
	bubblesort(list_one, list_size);
	bubblesort(list_two, list_size);

	int sum=0;
	for(int i=0; i<list_size; i++) {
		sum += abs(list_one[i] - list_two[i]);
	}
	printf("%d\n", sum);
}