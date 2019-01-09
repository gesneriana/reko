#region License
/* 
 * Copyright (C) 1999-2019 John Källén.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#endregion

using Reko.Core.Expressions;
using Reko.Core.Operators;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Reko.Evaluation
{
    public class ComparisonConstOnLeft
    {
        private Expression bin;

        public bool Match(BinaryExpression bin)
        {
            if (!(bin.Operator is ConditionalOperator cond))
                return false;
            if (!(bin.Left is Constant cLeft))
                return false;
            if (bin.Right is Constant)
                return false;
            this.bin = new BinaryExpression(
                cond.Transpose(),
                bin.DataType,
                bin.Right,
                cLeft);
            return true;
        }

        public Expression Transform()
        {
            return bin;
        }
    }
}