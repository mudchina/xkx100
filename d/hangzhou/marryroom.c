// marry_room.c
#include <room.h>
inherit ROOM;
string look_zhaopai(object me);
void create()
{
        set("short", "红娘庄");
        set("long", @LONG
你现在正站在风光秀丽的西子湖畔的红娘庄里，临水凭窗，隔着
碧绿的湖面，就是断桥了。红娘庄并不大，但这里却主天下之悲欢离
合，成就所有天下有情人。
    靠近门口的地方有一块乌木雕成的招牌(zhaopai)。
LONG);
        set("exits", ([
            "east" : __DIR__"road10",
        ]) );
        set("item_desc", ([
            "zhaopai": (: look_zhaopai :),
        ]) );
        set("objects", ([
            __DIR__"npc/hongniang" : 1,
        ]) );
        set("no_fight",1);
        set("no_steal",1);
        set("no_clean_up", 0);
	set("coor/x", 4140);
	set("coor/y", -1450);
	set("coor/z", 0);
	setup();
}

string look_zhaopai(object me)
{
        return "缔结(marry)或解除(unmarry)婚约。\n";
}