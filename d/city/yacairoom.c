// yacairoom.c.
// Last modified by winder 2002.11.11

inherit ROOM;

void create ()
{
	set("short", "押彩房");
	set("long", @LONG
这里摆着一个八仙桌，中间摆着一个银盘。赌客们正聚精会神地下
赌。正席是一位胖子，手里不断玩弄着一对玉骰，他就是这里的庄东。
    墙上挂有一个匾(bian)。
LONG);

	set("item_desc", (["bian" : "
ya tc <数量> <coin|silver|gold> 押头彩(两数顺序及点数均正确)       一赔卅五
ya dc <数量> <coin|silver|gold> 押大彩(两数点数正确)               一赔十七
ya sd <数量> <coin|silver|gold> 押双对(两数相同且均为偶数)         一赔十一
ya kp <数量> <coin|silver|gold> 押空盘(两数不同且均为偶数)         一赔五
ya qx <数量> <coin|silver|gold> 押七星(两数之和为七)               一赔五
ya dd <数量> <coin|silver|gold> 押单对(两数均为奇数)               一赔三
ya sx <数量> <coin|silver|gold> 押散星(两数之和为三、五、九、十一) 一赔二
每盘按从上到下的顺序只出现一种点型(头彩和大彩可同时出现)，其他情况都算庄家赢。
"
	]));
	set("exits", ([
		"west" : __DIR__"shaiziting",
	]));
	set("objects", ([
		__DIR__"npc/zhuangjia" : 1,
	]));

	set("no_fight", 1);
	set("no_beg", 1);
	set("no_magic", 1);
	set("no_clean_up", 1);
	set("coor/x", 22);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
