// Room: donglang2.c 东厢走廊
inherit RESTROOM_OUT;

void create()
{
    set("short", "东厢走廊");
    set("long", @LONG
你走在一条走廊上，隐约可以听到东边传来呼吸声，似乎有人正在
那里练功，北边有一扇门 (men)，好象是虚掩着。南边是间竹子扎就的
屋子，十分的素雅，里面飘出一阵阵的茶香，有人轻声细语地不知说那
些什么，引得女孩子“吃吃”笑出声来。
LONG );

    set("exits", ([
        "east" : __DIR__"liangongfang",
        "south" : __DIR__"chashi",
        "west" : __DIR__"donglang1",
    ]));
  set("no_clean_up", 0);
	set("coor/x", -2030);
	set("coor/y", -920);
	set("coor/z", 90);
	set("door_name","门");
	set("door_dir","north");
	set("restroom",__DIR__"xiuxishi");
	set("open_door_msg","门上挂了个牌子：南柯梦处。\n");
	set("inside_msg",   "门上挂了个牌子：请毋打扰\n");
	set("no_one_msg",   "门上挂了个牌子：休息室。\n");
	set("item_desc/door",(: look_men : ));
	set("item_desc/men", (: look_men : ));
	setup();
}
