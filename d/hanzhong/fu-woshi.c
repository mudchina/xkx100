// fu-woshi.c 卧室
// Winder Oct.10 1998

inherit ROOM;
int do_pull(string arg);

void create()
{
        set("short", "卧室");
        set("long", @LONG
这里是侯员外的卧室，卧室中央横拉着一道大帘子。在帘后
有一张雕着八仙过海的大床，床头有一个抽屉(drawer)。床上铺
丝陈缎，厚厚的锦被看起来很舒服，你不禁想在这里安然大睡了。
LONG
        );
        set("sleep_room",1);
        set("exits", ([
                "north" : __DIR__"fu-houyuan",
        ]));
        set("objects", ([
                __DIR__"npc/yuanwai" : 1,
        ]));
        set("item_desc", ([
        "drawer": "一个抽屉，好象可以拉(pull)开，里面可能有不少金银珠宝哦。\n"
        ]) );

	set("coor/x", -3130);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_pull","pull");
}

int do_pull(string arg)
{
        object me=this_player();

        if( !arg || arg != "drawer" ) {
                return notify_fail("你要拉开什么？\n");
        }

        message_vision("$N把抽屉拉开，还没来得及看里面有什么东西，只听得床板吱吱
连声，\n",this_player());
        message_vision("自动向两边分开，现出一个黑黝黝的洞口。\n", this_player());
        set("exits/down", __DIR__"fu-midao");
        remove_call_out("close");
        call_out("close", 5, this_object());

        return 1;
}

void close(object room)
{
        message("vision","床板又合了起来，把洞口封住了。\n", room);
        room->delete("exits/down");
}