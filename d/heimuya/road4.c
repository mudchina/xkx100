// Room: /d/heimuya/road4.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
        set("short", "黄土路");
	set("long", @LONG
你走在一条黄土路上。这里是山西地界，往东就进入河北了。现在
这里不是太平时节，还是快点走吧。
LONG );
        set("outdoors", "heimuya");
        set("exits", ([
                "northeast" : __DIR__"road1",
                "southwest" : __DIR__"dukou1",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3030);
	set("coor/y", 4020);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}