// Room: /u/cuer/emei/yhrkou.c
inherit ROOM;
void create()
{
        set("short", "云海入口");
        set("long", @LONG
这里就是峨嵋著名的云海了，放眼望去，漫山遍野都
是云雾，根本就弄不清自己身在何出。在雾中隐隐约约有
一条小道通向前方，还是回去吧。
LONG
        );
        set("exits", ([
            "enter" : __DIR__"hcahoudian",
            "north" : __DIR__"yunhai1",
        ]));
	set("no_clean_up", 0);
	set("coor/x", -6200);
	set("coor/y", -1190);
	set("coor/z", 200);
	setup();
        replace_program(ROOM);
}