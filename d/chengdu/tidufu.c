// Room: /chengdu/tidufu.c
// Date: Feb.14 1998 Java

inherit ROOM;

void create()
{
	set("short", "提督府");
	set("long", @LONG
这里便是提督大人办公事的地方。正前方 (front)大红楠木案桌后
正经端坐着的，就是成都提督吴天德。两边站立纹风不动的是他的亲兵
侍从，看上去都十分彪悍。
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"tidugate",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/wutiande" : 1,
		__DIR__"npc/shicong" : 2,
		__DIR__"npc/qinbing" : 4,
	]));
	set("item_desc",([
		"front" : "
                ###########################
                #                         #
                #    民   安   境   靖    #
                #                         #
                ###########################
                            !~A~!
                      @~~~~~!(O)!~~~~~@
                           (.@ @.)
                            . ~ .
                         /   ~.你奶奶的...你这刁民...还瞧甚么？不认得老爷么？...
                        #           #
             HHHH     #               #
             HHHH   #    n         n    #
          |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
           ```````````````````````````````````````
                  ()                      ()
                 ()                        ()
                ()                          ()
               ()                            ()\n"
	]));
	set("coor/x", -8040);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
