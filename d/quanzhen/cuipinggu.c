// cuipinggu.c 翠屏谷
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "翠屏谷");
        set("long", @LONG
你的面前是一座形如屏风的大山壁，山壁上郁郁葱葱都是树，一
眼看过去，全是一片翠绿色。这就是此地名叫翠屏谷的由来。从这里
继续北上，就到了终南山上的柏树林了。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southdown" : __DIR__"shanlu3",
                "northup" : __DIR__"baishulin1",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3140);
	set("coor/y", 20);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}