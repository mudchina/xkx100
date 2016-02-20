// /d/xiakedao/shihole2.c 侠客岛 石洞2

inherit ROOM;

int do_learn(string arg);
void create()
{
        set("short", "石洞");
        set("long", @LONG
此洞通向第二组石室。洞中水声淙淙，右面恰巧一道山泉流过。
中间四个草书大字深入石壁「飘渺烟云」，两侧均是蓝色帷幔环绕。
几名蓝衣弟子侍立。
LONG );
        set("exits", ([
                "out"   : __DIR__"shihole1",
                "enter" : __DIR__"shihole3",
                "north" : __DIR__"shiroom05",
                "south" : __DIR__"shiroom06",
                "east"  : __DIR__"shiroom07",
                "west"  : __DIR__"shiroom08",
        ]));
        set("objects", ([
                __DIR__"npc/maliu": 1,
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3090);
	set("coor/y", -25200);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{

        if (  (dir == "south")
           && ((int)me->query("PKS") > 10)
           && objectp(present("ma liu", environment(me))) )
                return notify_fail("马六把手一拦：你这种杀人狂魔，还敢到侠客岛来，快滚!\n");
        return ::valid_leave(me, dir);
}