// Room: nanyan0.c 南岩宫地下室
// Date: Oct.5 1997
#include <login.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "南岩宫地下室");
        set("long", @LONG
这是一个干燥洁净的地下室，四壁用光滑的大理石砌就，十数支松
明照得这里通明透亮。
LONG );
        set("objects", ([
           CLASS_D("wudang") +"/xiaosong": 1,
        ]));

        set("exits", ([
//              "up"     : __DIR__"nanyangong",
                "east"   : __DIR__"nanyan1",
                "west"   : __DIR__"nanyan2",
                "south"  : __DIR__"nanyan3",
                "north"  : __DIR__"nanyan4",
        ]));
//        set("no_clean_up", 0);
        set("coor/x", -2040);
	set("coor/y", -960);
	set("coor/z", 70);
	setup();
}

int valid_leave(object me, string dir)
{
	string fskill;
    if ( dir == "up" )
    {
    	fskill = me->query_skill_mapped("force");
       if ( !fskill || me->query_skill(fskill, 1) < 80 )
          {
              return notify_fail("你试着推了推顶上的砖盖，触手冰凉，纹丝不动。\n"
              + "哈哈，你完蛋了。\n");
          }
          message_vision( HIY
            "$N全身运足"+to_chinese(fskill)+"，拔身错步，嘿地一声，举起双掌向上猛击。只见\n"
            "一股白气自$N掌心而出，迅猛无比地击中顶上的砖盖。克剌剌一声\n"
            "巨响，砖盖被震成无数小碎片四散飘飞。露出一个向上的洞口来。\n" NOR, me );
       me->move(__DIR__"nanyangong");
       return notify_fail("");
     }
     return ::valid_leave(me, dir);
}
