// /d/city/xiangqishi.c
#include <ansi.h>
inherit  ROOM;

string look_book();
string look_jian();
string look_lian();

void create ()
{
	set ("short", "象棋室");
	set ("long", @LONG
适情雅趣屋里很是雅致。当中一座大棋盘，棋盘上楚河汉界，将士
跃马横炮，《战国策·秦》云：“缀甲历兵，效胜于战场。”诚如是也。
棋盘边的小几上搁着一叠薛涛笺(jian)，密密麻麻写满不少东西，还有
一些好象是棋经(jing)、诗歌(poem)、棋诀(book)之类的，抄录得很整
齐，想来颇值一读(read)。宋·刘克庄《象弈一首呈叶潜仲》诗云：“
小艺无难精，上智有未解。君看橘中戏，妙不出局外。”何不领略一番？ 
    墙上正北墙上挂了几副对联(lian)，桌头贴了一张小帖子(tie)。
LONG);

	set("no_fight",  1);
	set("objects", ([ /* sizeof() == 4 */
		__DIR__"obj/chess" : 1,
	]));
	set("item_desc", ([ 
		"poem": HIY"\n	象棋歌诀\n\n"NOR,
		"jing": HIR"\n	棋经论\n\n"NOR,
		"book": (: look_book :),
		"jian": (: look_jian :),
		"lian": (: look_lian :),
		"tie":
"

下子        ：move <横座标> <纵座标> to <横座标> <纵座标>
重下        ：reset
读出残局    ：deploy
记录残局    ：csave
掷骰确定先行：toss
回顾        ：review
认输        ：lose
观看棋局    ：look或l board或ccb

",
	]));
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"qiyiting",
	]));
	set("no_clean_up", 0);
	set("coor/x", 21);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_read", "read");
}
int do_read(string arg)
{
	if (arg == "poem")
		this_player()->start_more(read_file(__DIR__"obj/chess_book"));
	else
	if (arg == "jing")
		this_player()->start_more(read_file(__DIR__"obj/chess_jing"));
	else
                return notify_fail("你要读什么？\n");
	return 1;
}
string look_jian()
{
        return
" 
                     以战争之象为棋戏

    回溯历史，春秋时的战争主要是车战，是四马拉的各种战车。
    战车纵聘于平原之上，却会受到不平坦地形的阻滞，而步兵则无论密草丛
林、丘陵险隘，……这些地带对战车是畏途，对步兵则无往而不利。所以到了
战国时期，步兵部队就庞大了起来，形成了以步兵部队为主体，配置以战车的
军队。骑兵的发展，自赵武王“胡服骑射”运动之后，从而使战术是形成步、
骑、车（即车马兵）的协同作战的战术联合体，使得战术组织复杂了许多。
    早期的象棋，在定型前除去无炮外，车、马、兵齐备，这与古代战争中的
兵种是一致的，尤其是五个兵卒，正好符合“五兵为伍”的战争中的战术组合
体。\n"+"
    象棋中的不同兵种协同联攻的战术组合体很多，举不胜举。诸如：五兵联
攻，可以形成“五卒擒王”之势；车马联攻，俗称“车马冷着”令受攻者防不
胜防；车炮联攻，能形成“夹车炮”、“滚地雷”以及抽将得子等有迅猛威肋
的杀势，等等。
    出棋制胜犹如将帅之立奇功，李白计曰：“剪虏若草收奇功！”（《送族
弟馆从军安西》）的机巧战术，精妙的胜局，使棋迷荡气回肠，如饮甘醴，回
味无穷，妙不可言，是一种超脱世俗的艺术享受！
";
}

string look_book()
{
	string desc, *msg;
	
	desc = "小册子上写了一些和象棋有关的口诀或诗词，其中一页写着：\n\n";
	
	msg = ({
"【象棋十诀】：
一、开局宜正	二、中变出奇	叁、残局稳细	四、全局审势	五、车占要津
六、马路疏通	七、炮贵机动	八、兵卒猛进	九、相仕阻敌	十、将帅主攻\n\n",
"棋子全盘叁十二，半为黑色半为红，鸿沟划处分河界，九路纵横尽可通。\n\n",
"将军挂帅决雌雄，卫士相随镇九宫，象跨方田隔南北，车行直道任西东，
马经斜日防旁塞，炮越重峦利远攻，兵卒勇前无退缩，渡河一步可横通。\n\n",
"绿树为麾盖，荫下设棋局，赢者自得意，输者气呼呼。\n\n",
"当头一炮得先多，马後车前卒渡河，乘胜进攻应反顾，失机坚守切求和。\n\n",
"象棋法与用兵同，谋算全凭布局工，胜气争先终得势，贪多恋子必无功；
虚心量敌休妄应，刻意求河戒急攻，成败寻常何畏怯，熟能生巧自精通。\n\n",
	});
	desc += msg[random(sizeof(msg))];
	return desc;
}

string look_lian()
{
	string desc, *msg;
	
	desc = "墙上是几副装裱得十分古雅得对联，其中一联写着：\n\n";
	
	msg = ({
HIR"
		※※※※※※※※※※※※※
		※※※观棋不语真君子※※※
		※※※起手无回大丈夫※※※
		※※※※※※※※※※※※※\n\n"NOR,
HIG"	****** ******
	* 香 * * 水 *
	* 分 * * 汲 *
	* 花 * * 石 *
	* 上 * * 中 *
	* 露 * * 泉 *
	****** ******\n\n"NOR,
HIC"	****** ******
	* 鼙 * * 畅 *
	* 报 * * 谈 *
	* 捷 * * 画 *
	* 音 * * 事 *
	* 一 * * 两 *
	* 壶 * * 腋 *
	* 春 * * 生 *
	* 暖 * * 风 *
	****** ******\n\n"NOR,
MAG"	****** ******
	* 瓦 * * 茗 *
	* 壶 * * 碗 *
	* 请 * * 香 *
	* 客 * * 腾 *
	* 邀 * * 遗 *
	* 请 * * 睡 *
	* 客 * * 魔 *
	****** ******\n\n"NOR,

	});
	desc += msg[random(sizeof(msg))];
	return desc;
}

