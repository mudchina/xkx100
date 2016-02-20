// hsk.c 哈萨克帐篷
inherit ROOM;
void create()
{
        set("short", "哈萨克帐篷");
        set("long", @LONG
这是哈萨克族人居住的帐篷，方圆两三丈，正中以一粗木做主梁，四
周用小木桩围成一圈，从主梁拉牛皮帐篷过木桩再钉于地上。草原上居住
的民族都喜欢这种帐篷，方便简单。因蒙古族人数最多，所以又统称这种
帐篷为“蒙古包”。
LONG);
        set("exits", ([
            "west" : __DIR__"majiu",
            "northeast" : __DIR__"caoyuan",
   //         "north" : __DIR__"caoyuan1",
            "southwest" : __DIR__"room-che",
         ]));
         set("objects", ([
                    __DIR__"npc/hasake1" : 1,
                    __DIR__"obj/cheese" : 1,
        ]));        
        setup();
        replace_program(ROOM);
}
