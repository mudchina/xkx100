// room-ji1.c

inherit ROOM;

void create()
{
        set("short", "小屋");
        set("long", @LONG
小屋中陈设简陋，但桌椅整洁，打扫得乾乾净净。一位老人正做在毡
子上整理着碗筷。四周放了些杂物，中间的小方木著上搁了几个瓦壶，飘
出阵阵诱人的香气。
LONG
        );
        set("exits", ([
            
            "out" : __DIR__"room-ji",
        ]));
        
        set("objects", ([
                    __DIR__"npc/ji" : 1,
      //              __DIR__"npc/li" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
