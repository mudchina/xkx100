// xiuxishi.c 休息室
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "休息室");
        set("long", @LONG
这是间很大的房间，光线非常昏暗。房里没有什么别的东西，
只有中间放着一张收拾得舒舒服服的大床，床上的被褥也整理得
整整洁洁，看着就让人想睡觉。
LONG
        );

        set("exits", ([
                "west" : __DIR__"wuchang2",
                "northwest" : __DIR__"wuchang1",
                "south" : __DIR__"shantang",
        ]));
        set("no_clean_up", 0);
        set("sleep_room",1);
        set("no_beg",1);
        set("no_fight",1);
        set("no_steal",1);

	set("coor/x", -2740);
	set("coor/y", 90);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}