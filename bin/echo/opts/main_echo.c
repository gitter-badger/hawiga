/**
 ** This file is part of BoneOS.
 **
 **   BoneOS is free software: you can redistribute it and/or modify
 **   it under the terms of the GNU General Public License as published by
 **   the Free Software Foundation, either version 3 of the License, or
 **   (at your option) any later version.

 **   BoneOS is distributed in the hope that it will be useful,
 **   but WITHOUT ANY WARRANTY; without even the implied warranty of
 **   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **   GNU General Public License for more details.

 **   You should have received a copy of the GNU General Public License
 **   along with BoneOS.  If not, see <http://www.gnu.org/licenses/>.
 **
 **  @main_author : Amanuel Bogale
 **  
 **  @contributors:

 **     Amanuel Bogale <amanuel2> : start
 **/  
 
#include <misc/status_codes.h>
#include <string/string.h>
#include <unistd/unistd.h>
#include <stdio/stdio.h>
#include <term/terminal.h>
#include <stdlib/stdlib.h>
#include <stdio/stdio.h>
#include <echo/echo.h>
#include <term/values.h>

int main_echo_opt_handler(char *cmd)
{
   size_t num_opts = get_opt_count(cmd);
   str_t opts[num_opts];
   get_opt(cmd,opts);
   
   char opts_one_key[strlen(opts[1].str)];
   
   for(int i=0; opts_one_key[i]; i++) opts_one_key[i] = 0;
   
   if(strcmp(opts[1].str , "--help")==0)
      printk(cmd_echo.help);
   else if(num_opts == 2)
   {
       if(opts[1].str[0] == '$')
       {
           for(int i=1; opts[1].str[i]; i++)
             opts_one_key[i-1] = opts[1].str[i];
          for(int i=0; i<__values.index; i++)
          {
             if(strcmp(__values.pairs[i].key, opts_one_key)==0)
             {
                printk("%s\n" , __values.pairs[i].val);
                return STATUS_OK;
             }
          }
       }
       printk("%s\n" , opts[1].str);
   }
   else
      printk(cmd_echo.invalid_use_msg);
    
   return STATUS_OK;
}


