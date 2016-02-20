// Room: /d/taohua/neishi2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "扫叶廊");
	set("long", @LONG
黄岛主卧室外的扫叶廊由青竹搭就，房里收拾得十分清雅。靠北窗
子透进一些些桃花的香味，以及一点点海水的清新腥味。窗下一张大竹
桌上放着几本翻着一半的书，上面尽是一些奇怪的符号，你看不懂。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"woshi2",
		"west"  : __DIR__"chufang",
		"south" : __DIR__"neishi1",
	]));
	set("outdoors","taohua");
	set("coor/x", 9000);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}