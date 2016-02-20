//Room: /d/huashan/shop.c

inherit ROOM;

void create()
{
	set("short", "小吃店");
	set("long", @LONG
这里是石梁边的一间小吃店，卖些简单的饮食，专门赚那些游客的
钱。
LONG );
     	set("exits", ([
            "west" : __DIR__"shiliang",
       	]));

        set("objects", ([
            "/d/city/npc/xiaoer2" : 1,
       	]));
//        set("no_clean_up", 0);
	set("coor/x", -2040);
	set("coor/y", -870);
	set("coor/z", 50);
	setup();
        replace_program(ROOM);
}
