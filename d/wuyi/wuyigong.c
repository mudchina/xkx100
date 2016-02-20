// Room: /d/wuyi/wuyigong.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "武夷宫");
	set("long", @LONG
武夷宫坐落在大王峰南麓，为武夷山门户。汉武帝遣使节在此设坛
祭祀武夷君。唐天宝年间，曾就近洲渚创建天宝殿；后改为会仙观，宋
大中祥符二年，奉旨扩建，增修屋宇三百余，规模宏大，富丽堂皇。南
宋绍圣二年，又大修宫殿，并改名为冲佑观，为南宋九大名观之一。朱
熹、陆游、辛弃疾等均在此任过提举或主管，并在此着书赋诗。元泰定
五年改称万年宫。明代戚继光路经武夷，留有《题万年宫壁》诗：一剑
横空星斗寒，甫随平虏复征蛮。他年觅取封侯印，愿向君王换此山。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : "/d/yanping/shandao1",
		"south" : __DIR__"1qu",
		"north" : __DIR__"path2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1400);
	set("coor/y", -5000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

