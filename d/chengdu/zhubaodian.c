// Room: /d/chengdu/zhubaodian.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
        set("short", "珠宝店");
        set("long", @LONG
这里就是全国闻名的“谢记”珠宝店。谢家做珠宝这一行已经有了
上百年的历史，以其选材上乘，制作精巧，花样繁多而为达官贵族所青
睐，因为如果身上佩带有“谢记”珠宝就是一种身份的象征。门口挂的
招牌虽然有些旧了，却显示出它历史的悠久。
LONG	);
        set("exits", ([                
                "east" : __DIR__"beijie2",                
        ]));
        set("objects", ([
                __DIR__"npc/yunyan" : 1,
                __DIR__"npc/huoji" : 1,
        ]));
        set("coor/x", -8060);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

 
