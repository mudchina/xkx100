// Room: /t/wanjiegu/road4.c

inherit ROOM;

void create()
{
        set("short", "大路");
        set("long", @LONG
这是一条云南的官道，南通大理城，北面不远处可以看到开封的城门
，大道上人来人往，热闹非凡。有赶道的，有经商的，也有腰悬利器的武
林豪杰。

LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : "/t/kaifeng/sgate",
  "south" : __DIR__"road3",
  "east" : "/u/g/gold/dock",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
