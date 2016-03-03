/* gpio.h
 * #defines and other info to associate GPIOs with their
 * respective system level functions
 *
 */

// NOTE: An "_n" suffix denotes an active low signal

//PORT A (0 - 31)
#define A0		0
#define A1		1
static const char *testled = "pioA0";
static const char *testint = "pioA1";

#define A2		2
#define A24		24

static const char *pmic_pbstat_n 	= "pioA2";
static const char *led 			= "pioA24";

//PORT B (32 - 63)
#define B4		36
#define B5		37
#define B6		38
#define B9		41
#define B10		42

static const char *fpga_irq_n 		= "pioB4";
static const char *accel_int1 		= "pioB5";
static const char *accel_int2 		= "pioB6";
static const char *wmod_disable_n 	= "pioB9";
static const char *mr_n 			= "pioB10";



//PORT C (64 - 95)
#define C0		64
#define C1		65
#define C2		66
#define C3		67
#define C4		68
#define C5		69
#define C6		70
#define C7		71
#define C8		72
#define C9		73
#define C10		74
#define C11		75
#define C12		76
#define C13		77
#define C14		78
#define C15		79
#define C16		80
#define C17		81
#define C18		82
#define C19		83
#define C20		84
#define C21		85
#define C22		86
#define C23		87
#define C24		88
#define C25		89
#define C26		90
#define C27		91
#define C28		92
#define C29		93
#define C30		94
#define C31		95


static const char *lamp1 			=  	"pioC0";
static const char *lamp2 			= 	"pioC1";
static const char *lamp3_12 		= 	"pioC2";
static const char *lamp4_13 		= 	"pioC3";
static const char *lamp5			= 	"pioC4";
static const char *lamp6			= 	"pioC5";
static const char *lamp7 			=	"pioC6";
static const char *lamp8 			=	"pioC7";
static const char *lamp9 			=	"pioC8";
static const char *lamp10			=	"pioC9";
static const char *lamp11 			=	"pioC10";
static const char *lamp14 			=	"pioC11";
static const char *lamp15 			=	"pioC12";
static const char *lamp16			=	"pioC13";
static const char *lamp17_21 		=	"pioC14";
static const char *lamp18_22 		=	"pioC15";
static const char *lamp19_23 		=	"pioC16";
static const char *lamp12_24		=	"pioC17";
static const char *lamp25 			=	"pioC18	";
static const char *sd_present_n 	=	"pioC20";
static const char *gps_led			=	"pioC21";
static const char *cell_led 		=	"pioC26";
static const char *rp_led0 		=	"pioC27";
static const char *rp_led1 		=	"pioC28";
static const char *rp_led2 		=	"pioC29	";
static const char *psw_1			=	"pioC30";
static const char *psw2 			=	"pioC31";


//PORT D (96 - 127)
#define D0		96
#define D1		97
#define D2		98
#define D3		99
#define D4		100
#define D5		101
#define D6		102
#define D7		103
#define D8		104
#define D9		105
#define D10		106
#define D11		107
#define D12		108
#define D13		109
#define D14		110
#define D15		111
#define D16		112
#define D17		113
#define D18		114
#define D19		115
#define D20		116

static const char *pmic_irq_n 				= "pioD0";
static const char *retract_relay_ff_d 		= "pioD1";
static const char *retract_relay_ff_clk 	= "pioD2";
static const char *extend_relay_ff_d 		= "pioD3";
static const char *extend_relay_ff_clk 	= "pioD4";
static const char *ff1q2_n 				= "pioD5";
static const char *ff2q2_n 				= "pioD6";
static const char *act_ret_status_n 		= "pioD7";
static const char *act_ext_status_n 		= "pioD8";
static const char *act_ret_led 			= "pioD9";
static const char *act_ext_led 			= "pioD10";
static const char *act_ret_sw_n 			= "pioD11";
static const char *act_ext_sw_n 			= "pioD12";
static const char *led_wwan_n				= "pioD13";
static const char *wmod_reset_n 			= "pioD14";
static const char *module_reconfig 		= "pioD15";
static const char *simin 					= "pioD16";
static const char *master_slave 			= "pioD17";
static const char *local_remote 			= "pioD18";
static const char *tp_rev 					= "pioD19";
static const char *intensity_lock 			= "pioD20";
static const char * lamp_sel 				= "pioD21";






