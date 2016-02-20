// Room: /d/wudujiao/shixi.c

inherit ROOM;

void create()
{
        set("short", "石隙");
        set("long", @LONG
这里是一道岩石的缝隙，窄得要人侧身挤过。你沿着曲折的岩缝
向前摸去，四周黑漆漆的，只有脚下的砂石发出轻微的声响。
LONG
        );

	set("no_clean_up", 0);
        set("exits", ([
              "down"     : __DIR__"baidu2",
              "westdown" : __DIR__"mishi",
        ]));

	set("coor/x", -44950);
	set("coor/y", -81120);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}