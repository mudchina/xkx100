// Room: /binghuo/shanlu2.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "石山小路");
	set("long", @LONG
走在火山石的寸草片叶不生的山路上。东下就是茂密的大树林了。
上面的山势非常陡，看来是爬不上去了。
LONG );
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown" : __DIR__"shanlu1",
	]));
	setup();
	replace_program(ROOM);
}

