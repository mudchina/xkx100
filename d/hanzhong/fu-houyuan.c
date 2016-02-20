// fu-houyuan.c 后院
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "后院");
        set("long", @LONG
这里是后院。走到这里，花香味更加浓烈了。你仔细一看，
东南边有一道圆形门，似乎花香是从那里传出来的。从这里再往
南走，就是侯员外的卧室了。
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "southeast" : __DIR__"houhuayuan",
                "north" : __DIR__"fu-datang",
                "south" : __DIR__"fu-woshi",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3130);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}