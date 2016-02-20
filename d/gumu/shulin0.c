// shulin0.c 树林
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "小树林");
	set("long", @LONG
走在小树林当中，你只闻铮铮琴声，一股淡淡白烟，带着极甜的花
香，自密林深处传出。一群乳白色的蜜蜂在你身旁飞来飞去。只见一块
石碑(shibei)立在当眼ㄦ处。往东是一块空地。其它方向尽是茂密的树
林。
LONG	);
	set("outdoors", "gumu");
	set("item_desc", ([
		"shibei" : 
"

                        终南古墓，
                        外人止步。

",
	]));
	set("exits", ([
		"west"    : __DIR__"shulin5",
		"east"    : __DIR__"shulin6",
		"north"   : __DIR__"shulin4",
		"southup" : __DIR__"shulin1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", 80);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}
