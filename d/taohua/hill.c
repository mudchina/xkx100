// Room: /d/taohua/hill.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "小山");
	set("long", @LONG
一翻上山头，你就发现眼前豁然开朗，北面山脚下是一大片的桃花
丛，而在花丛中隐约露出了几座庭院的飞檐，似乎有着一片典雅的建筑
在那边。向靠海的一边望去，用来爬山时垫脚的岩石已经被蹬掉了，你
再也回不到海边了。而东北边更有一座小山峰，十分险峻。
LONG
	);
	set("exits", ([ 
		"northdown" : __DIR__"taohua1",
		"eastup" : __DIR__"hill1",
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("coor/x", 8500);
	set("coor/y", -4690);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
