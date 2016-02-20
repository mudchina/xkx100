// lingpai1.c 赏善罚恶令

#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
        set_name("赏善罚恶令", ({ "ling pai", "pai" }));
        set("long", "这是一块深灰色的令牌，正面有一张笑脸，刻有赏善两个大字。\n"+
         "反面有一张生气的表情，刻有罚恶两个大子。这便是江湖上传说的赏善罚恶令。\n");
        set("weight", 300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 50000);
                set("material", "玉");
                set("armor_prop/armor", 2);
        }
        setup();
}
