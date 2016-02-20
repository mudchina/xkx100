// Room: /d/village/shack.c

inherit ROOM;

void create()
{
        set("short", "草棚");
	set("long", @LONG
这是一个简单的草棚，地上摆著一堆堆的货物，上山的游客可以在这
买些上山用品。草棚的墙上贴着个牌子，是个价目表(sign)。
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "north" : __DIR__"eroad1",
        ]));
        set("objects", ([
                __DIR__"npc/seller": 1 ]) );
        set("item_desc", ([ /* sizeof() == 1 */
        "sign" : "牌子上写道：
	手杖(stick)	一百文
	麻鞋(shoes)	一百五十文
	水壶(bottle)	一百文

		兼售 皮蛋(egg) 五十文，茶水(not yet) xx。 \n"
        ]));
//        set("no_clean_up", 0);

	set("coor/x", -940);
	set("coor/y", 260);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
 