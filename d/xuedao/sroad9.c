// sroad9.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","大雪山山谷");
        set("long",@LONG
山谷里遍地积雪，四周都是峭壁。只北面有一个出口，东面似乎有
个山洞。
LONG );
        set("exits",([
                "northdown" : __DIR__"wangyougu",
                "east"      : __DIR__"shandong2",
        ]));
        set("objects", ([
                CLASS_D("xueshan")+"/shengdi" :1,
        ]));
        set("outdoors", "xueshan");
	set("coor/x", -110000);
	set("coor/y", -55000);
	set("coor/z", 300);
	setup();
        replace_program(ROOM);
}