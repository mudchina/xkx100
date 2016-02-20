// Room: /d/xiangyang/walle1.c
// Date: Jan. 8 1999 by Winder
// Modified by Zeratul Jan 15 2001,限制了疯狂爬城

inherit __DIR__"wall.c";

void create()
{
	set("short", "石阶");
	set("long", @LONG
这是登向城头的石阶，因为城墙很高，所以很陡。石阶两
侧有可供拉车上下的斜坡道。
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"southup"   : __DIR__"walle3",
		"northdown" : __DIR__"eastgate1",
	]));
	set("coor/x", -450);
	set("coor/y", -510);
	set("coor/z", 10);
	setup();
}