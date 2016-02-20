// liufudating.c
// Date: Nov.1997 by Venus

#include <room.h>
inherit ROOM;
int do_knock(string arg);

void create()
{
        set("short", "刘府大厅");
        set("long", @LONG
刘府大厅里就安静多了。主人坐在太师椅上，神色抑郁。旁边坐着
一个黑衣老人，神情显得极为关切。老人膝上靠着一个小女孩。大厅正
中放着一张茶几，上面铺了锦缎。一只金光灿烂、径长尺半的黄金盆子，
放在茶几之上，盆中已盛满了清水。
LONG);
        set("exits", ([
            "west"   : __DIR__"liufuwest",
            "east"   : __DIR__"liufueast",
            "south"  : __DIR__"liufudayuan",
            "north"  : __DIR__"shanting",
        ]));
        set("objects", ([
                CLASS_D("henshan")+"/liu":1,
                __DIR__"npc/qu" : 1,
                __DIR__"npc/xiaoqu" : 1,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -400);
	set("coor/y", -1170);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
