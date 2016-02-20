// shijianyan.c 试剑岩
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "试剑岩");
        set("long", @LONG
石阶旁立着一块大岩石，上面斑斑驳驳的尽是砍伤。这块大岩
石便是全真教的试剑岩，天下的英雄来到这里，望着先辈们练剑时
在岩石上的砍痕，无不肃然起敬。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northdown" : __DIR__"shijie4",
                "southup" : __DIR__"shijie8",
                "east" : __DIR__"jiaobei",
        ]));
        set("objects",([
                CLASS_D("quanzhen")+"/yin" : 1,
                __DIR__"npc/daotong" : 2,
        ]));

	set("coor/x", -3150);
	set("coor/y", 110);
	set("coor/z", 160);
	setup();
        replace_program(ROOM);
}