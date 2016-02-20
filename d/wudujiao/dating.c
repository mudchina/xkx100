// Room: /d/wudujiao/dating.c

inherit ROOM;

void create()
{
        set("short", "大厅");
        set("long", @LONG
这里是个宽广的大厅，高大的盘龙柱一人都合抱不过来。这里是平日教
主召集教众们议事的地方，大厅正中供奉着五圣--毒蛇，蜘蛛，蜈蚣，蝎子
蟾蜍的画像。几位长老正坐在厅中议事 。
LONG
        );
        set("valid_startroom", 1);

        set("exits", ([
                "east" : __DIR__"huayuan1",
                "south" : __DIR__"jingshi",
                "west" : __DIR__"lianwu",
                "north" : __DIR__"shufang",
        ]));
        set("objects", ([
               CLASS_D("wudujiao")+"/first": 1,
               CLASS_D("wudujiao")+"/qiyunao": 1,
               CLASS_D("wudujiao")+"/panxiuda": 1,
               CLASS_D("wudujiao")+"/cenqisi": 1,
        ]));


	set("coor/x", -44910);
	set("coor/y", -81050);
	set("coor/z", 30);
	setup();
        "/clone/board/wudu_b"->foo();
}
int valid_leave(object me, string dir)
{
        int i;
        object ob;
        me=this_player();
        if(dir=="east"||dir=="north"||dir=="south")
        {
              if ((string)me->query("family/family_name")!="五毒教"
                 & objectp(present("qi yunao", environment(me))))
              return notify_fail("齐云敖身形一晃，忽然挡住你，厉声说道：这位" +
              RANK_D->query_respect(me) + "不是本教弟子，不得进入本教禁地。\n");
        }
        return ::valid_leave(me, dir);
}