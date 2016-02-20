// road4.c 山路
// by Xiang

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
你走在一条岩石嶙峋的山道上，左临深涧，涧水缓急，激石有
声。右边是悬崖，抬头隐约可见笼罩在云雾中的山峰，一路沿着山
潼渐行渐高。
LONG );
        set("outdoors", "xiakedao");
        set("exits", ([
                "southup" : __DIR__"pubu",
                "northdown" : __DIR__"road3",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3000);
	set("coor/y", -22050);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}