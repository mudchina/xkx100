// Room: /d/beijing/jail.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "刑部大牢");
        set("long", @LONG
这里是刑部大牢，房间里只有一堆发霉陈年稻草，地上两个破
碗，墙角一个臭屎盆。四周围的墙壁全部用稻草填充，以防要犯撞
墙自杀，齐眼高开了一个尺许宽的小天窗(window)，透进一点绿色
和野虫鸣叫。隔壁房间犯人声嘶力竭的惨叫声一阵阵刺你的耳膜，
一刻不得安宁。
LONG );
        set("no_clean_up", 0);
        set("no_beg",1);
        set("no_fight",1);
        set("no_sleep_room",1);
        set("item_desc", ([
		"window": "太阳啊，我为什么感觉不到你的温暖？\n",
        ]));
        set("objects", ([
                __DIR__"npc/yuzu" : 1,
        ]));
        setup();
        "/clone/board/jail_b"->foo();
}

void init()
{
        object ob = this_player();

        ob->set("startroom", "/d/beijing/jail");
        ob->set("xkx_jail", 1);
        message("vision",
           HIY "只听牢房铁门匡地一响，一个昏昏沉沉的家伙被扔了进来！\n\n" NOR,
           environment(ob), ob);
        tell_object(ob, "狱卒嘿嘿地笑着：今儿个你可是大石头砸屎坑，激起公愤了你...！\n");
}
