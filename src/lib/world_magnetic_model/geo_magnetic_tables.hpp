/****************************************************************************
 *
 *   Copyright (c) 2020-2023 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#include <stdint.h>

static constexpr float SAMPLING_RES = 10;
static constexpr float SAMPLING_MIN_LAT = -90;
static constexpr float SAMPLING_MAX_LAT = 90;
static constexpr float SAMPLING_MIN_LON = -180;
static constexpr float SAMPLING_MAX_LON = 180;

static constexpr int LAT_DIM = 19;
static constexpr int LON_DIM = 37;


// *INDENT-OFF*
// Magnetic declination data in radians * 10^-4
// Model: WMM-2020,
// Version: 0.5.1.11,
// Date: 2024.4235,
static constexpr const int16_t declination_table[19][37] {
	//    LONGITUDE:   -180,  -170,  -160,  -150,  -140,  -130,  -120,  -110,  -100,   -90,   -80,   -70,   -60,   -50,   -40,   -30,   -20,   -10,     0,    10,    20,    30,    40,    50,    60,    70,    80,    90,   100,   110,   120,   130,   140,   150,   160,   170,   180,
	/* LAT: -90 */ {  25940, 24195, 22449, 20704, 18959, 17213, 15468, 13723, 11977, 10232,  8487,  6741,  4996,  3251,  1505,  -240, -1985, -3731, -5476, -7221, -8967,-10712,-12457,-14203,-15948,-17693,-19438,-21184,-22929,-24674,-26420,-28165,-29910, 31176, 29431, 27685, 25940, },
	/* LAT: -80 */ {  22501, 20376, 18441, 16670, 15032, 13496, 12033, 10623,  9249,  7899,  6568,  5250,  3942,  2637,  1329,     8, -1335, -2710, -4123, -5578, -7077, -8617,-10198,-11820,-13487,-15208,-16997,-18872,-20858,-22980,-25257,-27692,-30260, 29936, 27324, 24825, 22501, },
	/* LAT: -70 */ {  14990, 13589, 12458, 11491, 10617,  9781,  8936,  8046,  7092,  6071,  5001,  3909,  2827,  1775,   755,  -254, -1294, -2404, -3613, -4921, -6310, -7747, -9200,-10645,-12074,-13493,-14925,-16416,-18049,-19979,-22526,-26363, 30550, 24074, 19616, 16860, 14990, }, // WARNING! black out zone
	/* LAT: -60 */ {   8471,  8215,  7924,  7641,  7379,  7118,  6803,  6365,  5744,  4920,  3916,  2805,  1689,   670,  -201,  -950, -1677, -2507, -3526, -4740, -6086, -7466, -8792,-10003,-11066,-11962,-12674,-13167,-13339,-12891,-10772, -3351,  5094,  7771,  8509,  8618,  8471, }, // WARNING! black out zone
	/* LAT: -50 */ {   5524,  5556,  5494,  5396,  5315,  5272,  5232,  5099,  4749,  4078,  3060,  1784,   447,  -718, -1567, -2110, -2495, -2941, -3649, -4695, -5966, -7257, -8401, -9297, -9884,-10107, -9896, -9122, -7599, -5225, -2312,   438,  2549,  3976,  4850,  5323,  5524, },
	/* LAT: -40 */ {   3983,  4074,  4076,  4024,  3957,  3918,  3919,  3904,  3724,  3180,  2143,   692,  -868, -2163, -2998, -3422, -3584, -3633, -3821, -4439, -5462, -6557, -7438, -7959, -8043, -7638, -6725, -5331, -3626, -1935,  -484,   734,  1782,  2654,  3317,  3751,  3983, },
	/* LAT: -30 */ {   3008,  3093,  3116,  3093,  3028,  2944,  2879,  2843,  2712,  2223,  1169,  -365, -1970, -3201, -3911, -4230, -4284, -4045, -3606, -3433, -3862, -4637, -5326, -5650, -5496, -4884, -3909, -2706, -1516,  -589,    78,   676,  1305,  1918,  2436,  2805,  3008, },
	/* LAT: -20 */ {   2365,  2409,  2419,  2411,  2360,  2260,  2146,  2067,  1920,  1414,   336, -1169, -2642, -3677, -4177, -4264, -4034, -3447, -2575, -1809, -1588, -1981, -2634, -3084, -3096, -2718, -2073, -1264,  -506,   -33,   218,   516,   963,  1455,  1889,  2206,  2365, },
	/* LAT: -10 */ {   1972,  1964,  1934,  1920,  1884,  1792,  1673,  1577,  1390,   831,  -249, -1636, -2899, -3698, -3928, -3668, -3072, -2280, -1437,  -698,  -261,  -325,  -813, -1312, -1509, -1406, -1087,  -594,  -110,   115,   151,   306,   685,  1138,  1546,  1845,  1972, },
	/* LAT:   0 */ {   1757,  1722,  1658,  1639,  1620,  1542,  1427,  1305,  1048,   422,  -629, -1857, -2896, -3452, -3415, -2888, -2111, -1332,  -689,  -161,   242,   333,    36,  -381,  -626,  -677,  -578,  -321,   -41,    35,   -40,    42,   393,   853,  1288,  1621,  1757, },
	/* LAT:  10 */ {   1616,  1623,  1573,  1581,  1600,  1542,  1408,  1213,   835,   116,  -908, -1979, -2787, -3098, -2865, -2241, -1461,  -757,  -252,   123,   444,   580,   404,    81,  -148,  -255,  -284,  -211,  -115,  -167,  -319,  -297,    14,   484,   980,  1399,  1616, },
	/* LAT:  20 */ {   1421,  1569,  1625,  1712,  1792,  1765,  1599,  1289,   743,  -111, -1150, -2090, -2667, -2752, -2405, -1793, -1081,  -438,    13,   316,   572,   710,   609,   364,   169,    49,   -53,  -128,  -217,  -416,  -661,  -721,  -479,   -19,   533,  1060,  1421, },
	/* LAT:  30 */ {   1104,  1469,  1728,  1950,  2107,  2113,  1919,  1491,   763,  -262, -1368, -2227, -2622, -2543, -2133, -1549,  -893,  -280,   175,   475,   702,   842,   813,   662,   515,   388,   219,    -7,  -302,  -683, -1055, -1213, -1046,  -611,   -29,   583,  1104, },
	/* LAT:  40 */ {    728,  1312,  1807,  2202,  2451,  2494,  2277,  1742,   833,  -384, -1603, -2449, -2752, -2589, -2139, -1544,  -890,  -264,   240,   599,   864,  1056,  1141,  1126,  1050,   898,   615,   185,  -368,  -981, -1500, -1737, -1613, -1192,  -594,    74,   728, },
	/* LAT:  50 */ {    416,  1159,  1842,  2405,  2777,  2888,  2663,  2014,   883,  -593, -1989, -2882, -3165, -2969, -2477, -1831, -1122,  -427,   184,   684,  1097,  1445,  1717,  1881,  1895,  1698,  1234,   501,  -410, -1315, -1984, -2258, -2126, -1686, -1059,  -338,   416, },
	/* LAT:  60 */ {    188,  1034,  1841,  2544,  3060,  3285,  3085,  2294,   814, -1101, -2783, -3750, -4001, -3744, -3176, -2435, -1613,  -777,    26,   773,  1460,  2085,  2620,  3007,  3154,  2948,  2281,  1132,  -302, -1617, -2468, -2762, -2593, -2107, -1430,  -647,   188, },
	/* LAT:  70 */ {   -106,   820,  1715,  2519,  3144,  3457,  3239,  2174,    55, -2547, -4471, -5316, -5353, -4892, -4139, -3218, -2204, -1146,   -78,   976,  1997,  2958,  3820,  4518,  4952,  4961,  4313,  2785,   547, -1564, -2844, -3275, -3117, -2598, -1867, -1017,  -106, }, // WARNING! black out zone
	/* LAT:  80 */ {  -1005,   -88,   760,  1451,  1850,  1722,   695, -1551, -4425, -6507, -7354, -7322, -6767, -5901, -4848, -3675, -2429, -1138,   176,  1496,  2805,  4085,  5311,  6451,  7449,  8212,  8552,  8075,  6006,  1926, -1820, -3500, -3817, -3461, -2774, -1923, -1005, }, // WARNING! black out zone
	/* LAT:  90 */ { -29117,-27371,-25626,-23881,-22135,-20390,-18645,-16900,-15154,-13409,-11664, -9918, -8173, -6428, -4682, -2937, -1192,   554,  2299,  4044,  5790,  7535,  9280, 11026, 12771, 14516, 16262, 18007, 19752, 21498, 23243, 24988, 26734, 28479, 30224,-30862,-29117, }, // WARNING! black out zone
};
static constexpr float WMM_DECLINATION_MIN_RAD = -3.086; // latitude: 90, longitude: 170
static constexpr float WMM_DECLINATION_MAX_RAD = 3.118; // latitude: -90, longitude: 150


// Magnetic inclination data in radians * 10^-4
// Model: WMM-2020,
// Version: 0.5.1.11,
// Date: 2024.4235,
static constexpr const int16_t inclination_table[19][37] {
	//    LONGITUDE:   -180,  -170,  -160,  -150,  -140,  -130,  -120,  -110,  -100,   -90,   -80,   -70,   -60,   -50,   -40,   -30,   -20,   -10,     0,    10,    20,    30,    40,    50,    60,    70,    80,    90,   100,   110,   120,   130,   140,   150,   160,   170,   180,
	/* LAT: -90 */ { -12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560,-12560, },
	/* LAT: -80 */ { -13641,-13507,-13346,-13166,-12973,-12772,-12568,-12369,-12179,-12003,-11847,-11713,-11603,-11517,-11454,-11412,-11392,-11394,-11421,-11475,-11559,-11674,-11820,-11994,-12193,-12410,-12640,-12873,-13101,-13313,-13499,-13648,-13750,-13800,-13796,-13740,-13641, },
	/* LAT: -70 */ { -14087,-13769,-13449,-13127,-12796,-12453,-12099,-11743,-11402,-11096,-10845,-10664,-10553,-10501,-10486,-10487,-10491,-10497,-10518,-10574,-10683,-10859,-11108,-11426,-11801,-12221,-12670,-13135,-13601,-14053,-14469,-14810,-14993,-14934,-14702,-14404,-14087, }, // WARNING! black out zone
	/* LAT: -60 */ { -13507,-13153,-12814,-12480,-12137,-11765,-11351,-10898,-10432,-10005, -9680, -9511, -9513, -9653, -9856,-10042,-10158,-10191,-10171,-10153,-10202,-10366,-10662,-11078,-11582,-12141,-12729,-13326,-13915,-14476,-14974,-15261,-15076,-14687,-14278,-13882,-13507, }, // WARNING! black out zone
	/* LAT: -50 */ { -12491,-12147,-11814,-11491,-11168,-10822,-10423, -9953, -9425, -8909, -8528, -8414, -8627, -9094, -9656,-10157,-10502,-10647,-10600,-10437,-10295,-10310,-10546,-10975,-11525,-12120,-12706,-13242,-13685,-13981,-14087,-14012,-13808,-13523,-13193,-12843,-12491, },
	/* LAT: -40 */ { -11239,-10887,-10536,-10189, -9850, -9513, -9154, -8731, -8212, -7652, -7238, -7217, -7697, -8531, -9451,-10270,-10914,-11328,-11442,-11250,-10898,-10635,-10648,-10947,-11419,-11925,-12366,-12680,-12833,-12836,-12747,-12613,-12436,-12205,-11918,-11588,-11239, },
	/* LAT: -30 */ {  -9603, -9217, -8832, -8440, -8048, -7675, -7322, -6936, -6425, -5818, -5381, -5496, -6298, -7517, -8764, -9847,-10746,-11436,-11805,-11763,-11369,-10861,-10544,-10564,-10826,-11148,-11398,-11500,-11432,-11256,-11087,-10959,-10819,-10616,-10334, -9986, -9603, },
	/* LAT: -20 */ {  -7375, -6922, -6495, -6063, -5619, -5192, -4807, -4403, -3842, -3161, -2734, -3038, -4195, -5829, -7450, -8798, -9839,-10590,-10998,-11002,-10613, -9987, -9437, -9209, -9269, -9433, -9568, -9577, -9399, -9129, -8943, -8869, -8777, -8576, -8260, -7843, -7375, },
	/* LAT: -10 */ {  -4421, -3867, -3400, -2957, -2499, -2051, -1644, -1203,  -588,   105,   440,   -36, -1416, -3361, -5326, -6899, -7957, -8559, -8797, -8710, -8275, -7573, -6911, -6580, -6550, -6643, -6756, -6772, -6580, -6287, -6145, -6175, -6155, -5948, -5565, -5030, -4421, },
	/* LAT:   0 */ {   -914,  -269,   211,   620,  1040,  1456,  1838,  2265,  2832,  3394,  3569,  3030,  1687,  -252, -2288, -3897, -4860, -5254, -5289, -5100, -4636, -3900, -3195, -2837, -2781, -2846, -2967, -3036, -2905, -2674, -2634, -2805, -2895, -2721, -2295, -1655,  -914, },
	/* LAT:  10 */ {   2553,  3199,  3647,  3994,  4351,  4717,  5061,  5432,  5866,  6220,  6234,  5714,  4596,  3006,  1321,   -22,  -785,  -999,  -887,  -638,  -209,   446,  1079,  1408,  1472,  1436,  1340,  1249,  1290,  1387,  1296,  1002,   784,   844,  1198,  1810,  2553, },
	/* LAT:  20 */ {   5411,  5953,  6341,  6641,  6955,  7297,  7634,  7969,  8288,  8474,  8371,  7887,  7030,  5922,  4801,  3914,  3412,  3319,  3486,  3739,  4080,  4556,  5017,  5269,  5330,  5321,  5278,  5219,  5203,  5177,  4991,  4639,  4322,  4224,  4397,  4828,  5411, },
	/* LAT:  30 */ {   7567,  7946,  8268,  8553,  8862,  9208,  9560,  9893, 10159, 10262, 10105,  9671,  9034,  8320,  7665,  7166,  6890,  6865,  7019,  7237,  7490,  7796,  8086,  8260,  8320,  8340,  8347,  8337,  8309,  8220,  7988,  7624,  7258,  7033,  7018,  7217,  7567, },
	/* LAT:  40 */ {   9266,  9488,  9745, 10031, 10356, 10715, 11079, 11412, 11657, 11731, 11573, 11208, 10734, 10263,  9872,  9596,  9456,  9462,  9581,  9748,  9929, 10117, 10290, 10415, 10495, 10560, 10620, 10653, 10632, 10516, 10267,  9910,  9537,  9250,  9108,  9121,  9266, },
	/* LAT:  50 */ {  10803, 10922, 11123, 11391, 11712, 12063, 12414, 12726, 12943, 12997, 12855, 12557, 12194, 11852, 11581, 11400, 11313, 11316, 11388, 11496, 11613, 11732, 11850, 11967, 12086, 12212, 12328, 12400, 12386, 12255, 12004, 11673, 11332, 11047, 10857, 10777, 10803, },
	/* LAT:  60 */ {  12320, 12390, 12537, 12752, 13019, 13316, 13616, 13879, 14053, 14080, 13945, 13699, 13412, 13144, 12926, 12773, 12686, 12659, 12678, 12729, 12800, 12887, 12996, 13130, 13291, 13469, 13634, 13740, 13741, 13615, 13388, 13108, 12830, 12594, 12424, 12332, 12320, },
	/* LAT:  70 */ {  13757, 13795, 13887, 14025, 14200, 14401, 14606, 14785, 14891, 14876, 14744, 14547, 14332, 14131, 13959, 13826, 13734, 13681, 13663, 13678, 13722, 13796, 13901, 14040, 14208, 14396, 14580, 14719, 14761, 14684, 14521, 14322, 14128, 13963, 13842, 13772, 13757, }, // WARNING! black out zone
	/* LAT:  80 */ {  14989, 14999, 15033, 15089, 15162, 15244, 15320, 15366, 15355, 15285, 15179, 15059, 14938, 14826, 14728, 14646, 14585, 14545, 14527, 14532, 14559, 14610, 14682, 14776, 14889, 15016, 15152, 15286, 15393, 15435, 15390, 15299, 15201, 15115, 15048, 15005, 14989, }, // WARNING! black out zone
	/* LAT:  90 */ {  15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, 15401, }, // WARNING! black out zone
};
static constexpr float WMM_INCLINATION_MIN_RAD = -1.526; // latitude: -60, longitude: 130
static constexpr float WMM_INCLINATION_MAX_RAD = 1.544; // latitude: 80, longitude: 110


// Magnetic strength data in milli-Gauss * 10
// Model: WMM-2020,
// Version: 0.5.1.11,
// Date: 2024.4235,
static constexpr const int16_t strength_table[19][37] {
	//    LONGITUDE:  -180, -170, -160, -150, -140, -130, -120, -110, -100,  -90,  -80,  -70,  -60,  -50,  -40,  -30,  -20,  -10,    0,   10,   20,   30,   40,   50,   60,   70,   80,   90,  100,  110,  120,  130,  140,  150,  160,  170,  180,
	/* LAT: -90 */ {  5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, 5440, },
	/* LAT: -80 */ {  6047, 5982, 5902, 5810, 5706, 5594, 5475, 5353, 5231, 5111, 4997, 4892, 4799, 4720, 4657, 4613, 4589, 4588, 4610, 4657, 4728, 4823, 4939, 5071, 5215, 5366, 5516, 5659, 5790, 5904, 5996, 6064, 6108, 6126, 6121, 6094, 6047, },
	/* LAT: -70 */ {  6292, 6156, 6004, 5838, 5658, 5465, 5259, 5045, 4826, 4611, 4409, 4228, 4071, 3941, 3837, 3761, 3715, 3704, 3734, 3811, 3941, 4123, 4354, 4623, 4919, 5227, 5531, 5815, 6064, 6268, 6418, 6512, 6552, 6543, 6492, 6405, 6292, },
	/* LAT: -60 */ {  6178, 5983, 5779, 5569, 5348, 5113, 4856, 4577, 4286, 3997, 3731, 3505, 3327, 3194, 3096, 3022, 2972, 2952, 2980, 3072, 3244, 3499, 3829, 4218, 4642, 5077, 5498, 5881, 6205, 6452, 6614, 6690, 6690, 6626, 6510, 6356, 6178, },
	/* LAT: -50 */ {  5837, 5604, 5370, 5138, 4904, 4658, 4387, 4083, 3755, 3424, 3123, 2885, 2726, 2637, 2588, 2553, 2518, 2490, 2496, 2571, 2749, 3045, 3447, 3922, 4430, 4936, 5410, 5828, 6165, 6405, 6541, 6580, 6535, 6423, 6259, 6059, 5837, },
	/* LAT: -40 */ {  5388, 5140, 4893, 4652, 4416, 4178, 3923, 3638, 3324, 2999, 2701, 2481, 2367, 2343, 2362, 2381, 2383, 2368, 2354, 2385, 2522, 2806, 3232, 3751, 4299, 4822, 5286, 5671, 5961, 6147, 6234, 6235, 6164, 6031, 5848, 5628, 5388, },
	/* LAT: -30 */ {  4875, 4632, 4391, 4155, 3928, 3708, 3489, 3257, 3001, 2725, 2469, 2289, 2223, 2250, 2317, 2386, 2450, 2496, 2514, 2525, 2598, 2807, 3180, 3675, 4209, 4703, 5117, 5429, 5629, 5727, 5753, 5725, 5645, 5511, 5330, 5113, 4875, },
	/* LAT: -20 */ {  4319, 4104, 3893, 3687, 3491, 3308, 3139, 2975, 2796, 2596, 2406, 2275, 2238, 2286, 2377, 2487, 2614, 2739, 2821, 2853, 2880, 2985, 3235, 3628, 4081, 4506, 4849, 5079, 5180, 5187, 5156, 5109, 5027, 4899, 4732, 4534, 4319, },
	/* LAT: -10 */ {  3789, 3626, 3471, 3324, 3188, 3068, 2964, 2870, 2771, 2655, 2532, 2435, 2394, 2424, 2514, 2645, 2800, 2955, 3074, 3132, 3145, 3176, 3308, 3567, 3897, 4219, 4480, 4638, 4670, 4616, 4548, 4486, 4398, 4273, 4124, 3959, 3789, },
	/* LAT:   0 */ {  3412, 3317, 3232, 3158, 3102, 3063, 3036, 3015, 2988, 2938, 2858, 2765, 2688, 2663, 2710, 2816, 2948, 3082, 3195, 3267, 3296, 3319, 3399, 3562, 3774, 3989, 4167, 4269, 4273, 4204, 4115, 4023, 3913, 3781, 3646, 3521, 3412, },
	/* LAT:  10 */ {  3282, 3250, 3228, 3223, 3247, 3293, 3347, 3397, 3429, 3418, 3348, 3235, 3110, 3020, 3000, 3044, 3127, 3226, 3325, 3410, 3473, 3536, 3627, 3748, 3886, 4026, 4146, 4214, 4214, 4150, 4039, 3895, 3733, 3574, 3437, 3340, 3282, },
	/* LAT:  20 */ {  3399, 3400, 3424, 3476, 3566, 3686, 3812, 3927, 4006, 4016, 3943, 3802, 3637, 3502, 3431, 3423, 3461, 3535, 3633, 3731, 3822, 3922, 4035, 4147, 4258, 4372, 4475, 4540, 4548, 4487, 4348, 4144, 3916, 3706, 3542, 3439, 3399, },
	/* LAT:  30 */ {  3722, 3725, 3777, 3874, 4015, 4184, 4357, 4512, 4618, 4644, 4571, 4417, 4231, 4071, 3971, 3928, 3935, 3989, 4078, 4178, 4277, 4384, 4501, 4619, 4740, 4869, 4991, 5077, 5101, 5040, 4881, 4640, 4365, 4110, 3909, 3779, 3722, },
	/* LAT:  40 */ {  4222, 4215, 4277, 4397, 4561, 4746, 4928, 5084, 5188, 5214, 5147, 5000, 4817, 4647, 4523, 4450, 4428, 4453, 4516, 4597, 4685, 4784, 4899, 5033, 5185, 5348, 5501, 5610, 5646, 5588, 5430, 5191, 4917, 4658, 4447, 4299, 4222, },
	/* LAT:  50 */ {  4832, 4819, 4870, 4976, 5120, 5278, 5427, 5549, 5623, 5634, 5572, 5448, 5288, 5127, 4993, 4898, 4846, 4837, 4863, 4915, 4986, 5078, 5198, 5349, 5525, 5710, 5876, 5991, 6032, 5985, 5852, 5657, 5433, 5219, 5039, 4907, 4832, },
	/* LAT:  60 */ {  5393, 5375, 5398, 5456, 5540, 5633, 5721, 5789, 5824, 5818, 5766, 5674, 5556, 5429, 5313, 5218, 5153, 5121, 5121, 5150, 5207, 5295, 5414, 5562, 5729, 5896, 6042, 6143, 6185, 6160, 6077, 5952, 5808, 5667, 5544, 5451, 5393, },
	/* LAT:  70 */ {  5726, 5702, 5696, 5705, 5725, 5751, 5775, 5791, 5793, 5776, 5739, 5684, 5616, 5541, 5469, 5406, 5359, 5332, 5329, 5349, 5395, 5465, 5557, 5666, 5783, 5897, 5995, 6066, 6104, 6107, 6078, 6025, 5958, 5888, 5822, 5767, 5726, },
	/* LAT:  80 */ {  5790, 5772, 5756, 5743, 5732, 5722, 5712, 5701, 5687, 5670, 5649, 5625, 5599, 5573, 5549, 5530, 5517, 5513, 5518, 5534, 5560, 5595, 5638, 5686, 5736, 5783, 5826, 5860, 5883, 5896, 5898, 5890, 5876, 5856, 5834, 5812, 5790, },
	/* LAT:  90 */ {  5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, 5686, },
};
static constexpr float WMM_STRENGTH_MIN_GS = 22.2; // latitude: -30, longitude: -60
static constexpr float WMM_STRENGTH_MAX_GS = 66.9; // latitude: -60, longitude: 130
static constexpr float WMM_STRENGTH_MEAN_GS = 46.4;
static constexpr float WMM_STRENGTH_MEDIAN_GS = 48.7;


