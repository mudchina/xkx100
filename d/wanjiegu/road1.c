// Room: /t/wanjiegu/road1.c

inherit ROOM;

void create()
{
        set("short", "大路");
        set("long", @LONG
这是一条云南的官道，南通大理城，北连中原腹地。大道上人
来人往，热闹非凡。有赶道的，有经商的，也有腰悬利器的武林豪
杰。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road2",
  "south" : "/t/dali/n_gate",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
