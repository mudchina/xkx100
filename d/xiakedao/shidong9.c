// shidong9.c 石洞

inherit ROOM;

void create()
{
        set("short", "石洞");
        set("long", @LONG
这是一个很小的石洞，两边点着红烛，光线虽暗，却也能辩得
出方向。走着走着，你隐约看见在前面有一个身影，只见他身穿青
色长衫，眼视前方，一副唯我独尊的样子。
LONG );
        set("exits", ([
                "west" : __DIR__"shidong10",
                "east" : __DIR__"yadi",
        ]));
        set("objects",([
                __DIR__"npc/baishou" : 1,
        ]));
	set("coor/x", -3100);
	set("coor/y", -22070);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{

        if (  (dir == "west")
           && ((int)me->query("shen") < 10000)
           || ((int)me->query("PKS") > 10)
           && objectp(present("bai shou",environment(me))) )
        return notify_fail
                ("白首把手一拦：你这种邪派人物，还敢到这来，快滚! \n");
        return ::valid_leave(me, dir);
}