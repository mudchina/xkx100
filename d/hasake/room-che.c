// room-che1.c

inherit ROOM;

void create()
{
        set("short", "车尔库的家");
        set("long", @LONG
车尔库的帐蓬中收拾得很整洁，一张张织著红花绿草的羊毛毯挂在四
周。矮桌上放着几个大酒碗，一个身材苗条的女孩子捧了酒浆出来笑嘻嘻
地看着你。
LONG
        );
        set("exits", ([
             "northeast" : __DIR__"hsk",
             "west" : __DIR__"caoyuan8",
             "south" : __DIR__"caoyuan8",
             "east" : __DIR__"caoyuan8",
        ]));

        set("objects", ([
                    __DIR__"npc/aman" : 1

        ]));
      
        setup();
        replace_program(ROOM);
}
