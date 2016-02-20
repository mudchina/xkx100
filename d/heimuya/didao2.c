// Room: /d/heimuya/didao2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","秘道");
	set("long", @LONG
你来到了一条秘道，看样子它不太平常，若隐若显的几盏油灯，昏
暗如豆但是看上去前方似有光亮，你要是觉得害怕，现在回头还是可以
的，不过这异常的幽静却也极大激发了你的好奇心，大丈夫死又何足道
哉，真是勇气可佳。
LONG );

	set("exits",([
		"down"  : "/d/city/shilijie4",
		"west"  : __DIR__"didao1", 
		"south" : __DIR__"didao5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3250);
	set("coor/y", 4210);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
