//room: mtdating.c
inherit ROOM;
void create()
{
        set("short","大厅");
        set("long",@LONG
这就是摩天崖了。上面光秃秃的，连一棵小树也没有，峰顶到
也十分开阔，但身周云雾缭绕，当真是置身云端之中，使人心惊肉
跳。东面有一个小木屋，门边立着一块青白色石碑(bei)。
LONG );
        set("outdoors", "motianya");
        set("exits",([
                "east" : __DIR__"mtxiaowu",
                "down" : __DIR__"mtyadi",
        ]));
        set("item_desc",([
                "bei" : "   『摩天崖』  \n无「玄铁令」者禁入！\n",
        ]));
        set("objects",([
                __DIR__"npc/xieyan" : 1,
        ]));
	set("coor/x", -2100);
	set("coor/y", -1700);
	set("coor/z", 30);
	setup();
}

int valid_leave(object me, string dir)
{
        if (  (dir == "east")
                && (!present("xuan tie",me))
                && objectp(present("xie yanke", environment(me))) )
        return notify_fail
                ("谢烟客把手一拦：你没有「玄铁令」，不能进去！\n");
        return ::valid_leave(me, dir);
}