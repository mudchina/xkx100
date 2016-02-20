//qiaobi1.c --spe

inherit ROOM;
void create()
{
	set("short","峭壁中");
	set("long",@LONG
峭壁半空中，向上望去，平台还很遥远，往下望去，下面
的一草一木都已变成一个个小黑点。风比峭壁底大得多，直吹
得你毛骨悚然，你开始有点后悔冒然爬这个峭壁了。
LONG
	);
	set("outdoors","jianzhong");
	set("climb_trigger",0);
	set("coor/x", -401);
	set("coor/y", -421);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}