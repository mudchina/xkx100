// fu-ceting 侧厅
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "侧厅");
        set("long", @LONG
这是正堂旁边的一间小厅，本来是用作书房的，只是侯员外
家实在找不出多少书来装点门面，所以就整治成了招待熟客的地
方。厅中摆放着一张八仙桌和几把椅子，桌上刚沏好的茶还在冒
着热气。
LONG
        );
        set("exits", ([
                "west" : __DIR__"fu-datang",
                "north" : __DIR__"fu-huating",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3120);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}